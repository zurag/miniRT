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

// float	get_light(t_vars *vars, float dist, t_vect *dir, t_vect	*normal)
// {
// 	t_vect	*origin;
// 	float	angle_inc;
// 	float	angle_ref;
//
// 	vect_multipl_on(dir, dist);
// 	origin = vec_subtraction(vars->light->d_point, dir);
// 	// vars->light->d_point;
// }
//phit = ray +

int	ft_pixel_color(t_vars *vars, t_vec *ray)
{
	int		color_from_light;
	float	dist1;
	t_vec	*phit;
	t_vec	*nhit;
	t_vec	*light;
	float	cos_alpha;

	vec_normalize(ray);
	color_from_light = 0;
	dist1 = sphere_intersect(vars->camera, ray, vars->sph);
	if (dist1)
	{
		vec_mult(ray, dist1);
		phit = vec_sum(vars->camera->d_origin, ray);
		nhit = vec_subtraction(phit, vars->sph->center);
		vec_normalize(nhit);
		light = vec_subtraction(phit, vars->light->d_point);
		cos_alpha = (dot_product(nhit, light)) / vec_len(light);
		color_from_light = ft_color(vars->sph->red * cos_alpha,
									vars->sph->green * cos_alpha,
									vars->sph->blue * cos_alpha);
		if (cos_alpha < 0)
			color_from_light = 0;
		return (color_from_light);
	}
	else
		return (0);
}

void	raytrace(t_vars *vars, t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	t_vec		*ray;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;
	int			color;
	// float		dist;

	vars->y = 0;
	printf("fov = %d\n", vars->camera->fov);
	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
	printf("width = %f, height = %f, x_pixel = %f, y_pixel = %f \n",
		   vplane->width, vplane->height, vplane->x_pixel, vplane->y_pixel);
	y_angle = HEIGHT / 2;
	while (y_angle > (HEIGHT / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1) ;
		vars->x = 0;
		while (x_angle < (WIDTH / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = vec_new(x_ray, y_ray, -1);
			color = ft_pixel_color(vars, ray);
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
	fov = 1;
	aspect_ratio = width * pow(height, (-1));
	vplane->width = 2 * tan((double)fov * 0.5);
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}
