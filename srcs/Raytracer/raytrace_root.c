/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:28:04 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_pixel_color(t_vars *vars, t_vec *ray, t_flist **figure)
{
	int		color_from_light;
	float	dist1;
	t_vec	*phit;
	t_vec	*nhit;
	t_vec	*light;
	float	cos_alpha;
	t_sph	*tmp_sph;
	t_plane	*tmp_plane;
	t_cyl	*tmp_cyl;
	t_flist	*tmp;

	vec_normalize(ray);
	color_from_light = 0;
	tmp = *figure;
	// TODO vars->dist - самая близкая дистанция. Именно эту точку мы красим
	// TODO vars->nearest_obj - указатель на конкретный токен с тем, что
	//  рисовать ( изменить интерсекты с учетом этой информации)
	while (tmp != NULL)
	{
		if (tmp->type == PLANE)
			dist1 = plane_intersect(vars->camera, ray, (t_plane *)tmp->content);
		else if (figure->type == SPHERE)
			dist1 = sphere_intersect(vars->camera, ray, (t_sph *)tmp->content);
		else if (figure->type == CYLINDER)
			dist1 = cylinder_intersect(vars->camera, ray, (t_cyl *)
			tmp->content);
		tmp = tmp->next;
	}
	//TODO здесь мы возвращаем еще и конкретную фигуру
	if (vars->dist)
	{
		vec_mult(ray, dist1);
		phit = vec_sum(vars->camera->d_origin, ray);
		if (figure->type == SPHERE)
		{
			tmp_sph = (t_sph *)figure->content;
			nhit = vec_subtraction(phit, tmp_sph->center);
			vec_normalize(nhit);
			light = vec_subtraction(phit, vars->light->d_point);
			cos_alpha = (dot_product(nhit, light)) / vec_len(light);
			if (cos_alpha < 0)
				cos_alpha = 0;
			color_from_light = ft_color(
					tmp_sph->red * (vars->amb->l_rat + cos_alpha),
					tmp_sph->green * (vars->amb->l_rat + cos_alpha),
					tmp_sph->blue * (vars->amb->l_rat + cos_alpha));
		}
		if (figure->type == PLANE)
		{
			tmp_plane = (t_plane *)figure->content;
			nhit = tmp_plane->nv_orientation;
			cos_alpha = (dot_product(nhit, light)) / vec_len(light);
			if (cos_alpha < 0)
				cos_alpha = 0;
			color_from_light = ft_color(
					tmp_plane->red * (vars->amb->l_rat + cos_alpha),
					tmp_plane->green * (vars->amb->l_rat + cos_alpha),
					tmp_plane->blue * (vars->amb->l_rat + cos_alpha));
		}
		if (figure->type == CYLINDER)
		{
			tmp_cyl = (t_cyl *)figure->content;
			nhit = vec_subtraction(phit, tmp_cyl->center);
			vec_normalize(nhit);
			cos_alpha = (dot_product(nhit, light)) / vec_len(light);
			if (cos_alpha < 0)
				cos_alpha = 0;
			color_from_light = ft_color(
					tmp_cyl->red * (vars->amb->l_rat + cos_alpha),
					tmp_cyl->green * (vars->amb->l_rat + cos_alpha),
					tmp_cyl->blue * (vars->amb->l_rat + cos_alpha));
		}
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
//	printf("fov = %d\n", vars->camera->fov);
	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
//	printf("width = %f, height = %f, x_pixel = %f, y_pixel = %f \n",
//		   vplane->width, vplane->height, vplane->x_pixel, vplane->y_pixel);
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
//	fov = 1;
	aspect_ratio = width * pow(height, (-1));
	vplane->width = 2 * tan((double)fov * 0.5);
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}
