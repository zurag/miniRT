/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/28 16:38:33 by zurag            ###   ########.fr       */
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
		color_from_light = get_plane_color(vars, ret_inter, figure, ray_dir);
	if (ret_inter->type == CYLINDER)
		color_from_light = get_cylinder_color(vars, ret_inter, figure, ray_dir);
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
		free(ret_inter);
		return (color_from_light);
	}
	else
		return (0);
}

void	raytrace(t_vars *vars, t_flist **figure)
{
	float		x_angle;
	float		y_angle;
	t_vec		*ray_dir;
	t_vec		*ray_new;
	t_vec		*to;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;
	int			color;
	t_matrix	*cam_to_world;

	vars->y = 0;
	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
	y_angle = HEIGHT / 2;
	to = vec_new(0, 0, -1);
	ray_new = vec_new(0, 0, 0);
	cam_to_world = look_at(vars->camera->nv_direction, to);
	free(to);
	while (y_angle > (HEIGHT / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (WIDTH / 2) * (-1);
		vars->x = 0;
		while (x_angle < (WIDTH / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray_dir = vec_new(x_ray, y_ray, vars->camera->nv_direction->z);
			vec_normalize(ray_dir);
			mult_dir_matrix(ray_dir, ray_new, cam_to_world);
			color = ft_pixel_color(vars, ray_new, figure);
			ft_mlx_pixel_put(vars->img, vars->x, vars->y, color);
			free(ray_dir);
			vars->x++;
			x_angle++;
		}
		y_angle--;
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	free(vplane);
	free(ray_new);
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
