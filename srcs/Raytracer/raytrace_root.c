/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/14 18:33:26 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_color(t_vars *vars, t_inter *ret_inter)
{
	int		color_from_light;

	if (ret_inter->type == SPHERE)
		color_from_light = get_sphere_color(vars, ret_inter);
	if (ret_inter->type == PLANE)
		color_from_light = get_plane_color(vars, ret_inter);
	if (ret_inter->type == CYLINDER)
		color_from_light = get_cylinder_color(vars, ret_inter);
	return (color_from_light);
}

int	ft_pixel_color(t_vars *vars, t_vec *ray, t_flist **figure)
{
	int		color_from_light;
	t_inter	*ret_inter;

	color_from_light = 0;
	ret_inter = intersect(ray, *figure, vars->camera->d_origin);
	// printf("type = %d\n", ret_inter->type);
	// printf("dist == %f\n", ret_inter->dist);
	// print_vect(ret_inter->norm, "ret_inter->norm");
	// print_vect(ret_inter->point, "ret_inter->point");
	if (!ret_inter)
		return (0);
	if (ret_inter->dist != -1)
	{
		color_from_light = get_color(vars, ret_inter);
		return (color_from_light);
	}
	else
		return (0);
}

void	raytrace(t_vars *vars, t_flist **figure)
{
	float		x_angle;
	float		y_angle;
	t_vec		*ray;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;
	int			color;

	vars->y = 0;
	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
	y_angle = HEIGHT / 2;
	while (y_angle > (HEIGHT / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (WIDTH / 2) * (-1);
		vars->x = 0;
		while (x_angle < (WIDTH / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vec_new(x_ray, y_ray, -1);
//			vec_normalize(ray);
//			printf("check\n");
			color = ft_pixel_color(vars, ray, figure);
			ft_mlx_pixel_put(vars->img, vars->x, vars->y, color);
			free(ray);
			vars->x++;
//			printf("var->x = %d, vars->y = %d\n", vars->x, vars->y);
			x_angle++;
		}
		y_angle--;
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
//	printf("check after loop\n");
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

//	printf("fov = %f\n", fov);
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
