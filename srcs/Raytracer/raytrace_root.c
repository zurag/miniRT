/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 21:18:46 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color(t_vars *vars, t_inter *ret_inter, t_flist *figure, t_vec *ray_dir)
{
	int		color_from_light;

	color_from_light = 0;
	if (ret_inter->type == SPHERE)
		color_from_light = get_sphere_color(vars, ret_inter, figure, ray_dir);
	if (ret_inter->type == PLANE)
		color_from_light = get_plane_color(vars, ret_inter, figure);
	if (ret_inter->type == CYLINDER)
		color_from_light = get_cylinder_color(vars, ret_inter, figure);
	return (color_from_light);
}

int	ft_pixel_color(t_vars *vars, t_vec *ray, t_flist **figure)
{
	int		color_from_light;
	t_inter	*ret_inter;

	color_from_light = 0;
	vec_normalize(ray);
	ret_inter = intersect(ray, *figure, vars->camera->d_origin);
	if (!ret_inter)
		return (0);
	if (ret_inter->dist != -1)
	{
		color_from_light = get_color(vars, ret_inter, *figure, ray);
		free(ret_inter->point);
		free(ret_inter->norm);
		free(ret_inter);
		return (color_from_light);
	}
	free(ret_inter->point);
	free(ret_inter->norm);
	free(ret_inter);
	return (0);
}

static void	colcul_color(float angle_xy[2], t_vplane *vplane,
	t_vars *vars, t_flist **figure)
{
	t_vec		*ray_new;
	float		ray_xy[2];
	t_vec		*ray_dir;
	t_matrix	*cam_to_world;
	t_vec		*to;

	to = vec_new(0, 0, -1);
	cam_to_world = look_at(vars->camera->nv_direction, to);
	free(to);
	ray_new = vec_new(0, 0, 0);
	ray_xy[1] = angle_xy[1] * vplane->y_pixel;
	angle_xy[0] = (WIDTH / 2) * (-1);
	while (angle_xy[0] < (WIDTH / 2))
	{
		ray_xy[0] = angle_xy[0] * vplane->x_pixel;
		ray_dir = vec_new(ray_xy[0], ray_xy[1], vars->camera->nv_direction->z);
		vec_normalize(ray_dir);
		mult_dir_matrix(ray_dir, ray_new, cam_to_world);
		ft_mlx_pixel_put(vars->img, vars->x, vars->y,
			ft_pixel_color(vars, ray_new, figure));
		free(ray_dir);
		vars->x++;
		angle_xy[0]++;
	}
	free(cam_to_world);
	free(ray_new);
}

void	raytrace(t_vars *vars, t_flist **figure)
{
	float		angle_xy[2];
	t_vplane	*vplane;

	vars->y = 0;
	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
	angle_xy[1] = HEIGHT / 2;
	while (angle_xy[1] > (HEIGHT / 2) * (-1))
	{
		vars->x = 0;
		colcul_color(angle_xy, vplane, vars, figure);
		angle_xy[1]--;
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	free(vplane);
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width * pow(height, (-1));
	vplane->width = 2 * tan((double)fov * 0.5 * (3.14 / 180));
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}
