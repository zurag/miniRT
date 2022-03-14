/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/14 15:26:04 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO vars->dist - самая близкая дистанция. Именно эту точку мы красим.
//  vars->nearest_obj - указатель на конкретный токен с тем, что
//  рисовать (изменить интерсекты с учетом этой информации)
// float	get_dist(t_vars *vars, t_vec *ray, t_flist **figure)
// {
// 	t_flist	*tmp;

// 	vec_normalize(ray);
// 	tmp = *figure;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->type == PLANE)
// 			vars->dist = plane_intersect(vars->camera, ray,
// 							(t_plane *)tmp->content);
// 		else if (figure->type == SPHERE)
// 			vars->dist = sphere_intersect(vars->camera, ray,
// 							(t_sph *)tmp->content);
// 		else if (figure->type == CYLINDER)
// 			vars->dist = cylinder_intersect(vars->camera, ray,
// 							(t_cyl *)tmp->content);
// 		tmp = tmp->next;
// 	}
// }

int	get_color(t_vars *vars, t_vec *phit)
{
	int		color_from_light;

	if (vars->nearest_obj->type == SPHERE)
		color_from_light = get_sphere_color(vars, phit);
	if (vars->nearest_obj->type == PLANE)
		color_from_light = get_plane_color(vars, phit);
	if (vars->nearest_obj->type == CYLINDER)
		color_from_light = get_cylinder_color(vars, phit);
	return (color_from_light);
}

int	ft_pixel_color(t_vars *vars, t_vec *ray, t_flist **figure)
{
	int		color_from_light;
	t_vec	*phit;
	t_inter	*ret_inter;

	color_from_light = 0;
	// get_dist(vars, ray, figure);
	ret_inter = intersect(vars, ray, *figure, vars->camera->d_origin);
	
	//TODO здесь мы возвращаем еще и конкретную фигуру
	if (vars->dist)
	{
		// vec_mult(ray, vars->dist);
		// phit = vec_sum(vars->camera->d_origin, ray);
		color_from_light = get_color(vars, phit);
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
		x_angle = (WIDTH / 2) * (-1) ;
		vars->x = 0;
		while (x_angle < (WIDTH / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vec_new(x_ray, y_ray, -1);
			color = ft_pixel_color(vars, ray, figure);
//			printf("color = %d\n", color);
			ft_mlx_pixel_put(vars->img, vars->x, vars->y, color);
//			printf("vars->x = %d vars->y = %d\n", vars->x, vars->y);
			free(ray);
			vars->x++;
			x_angle++;
		}
		y_angle--;
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	printf("check after loop\n");
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width * pow(height, (-1));
	vplane->width = 2 * tan((double)fov * 0.5);
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}
