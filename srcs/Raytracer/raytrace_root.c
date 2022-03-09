/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/09 20:36:49 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



// float	get_light(t_vars *vars, float dist, t_vect *dir, t_vect	*normal)
// {
// 	t_vect	*origin;
// 	float	angle_inc;
// 	float	angle_ref;

// 	vect_multipl_on(dir, dist);
// 	origin = vec_sum(vars->camera->d_origin, dir);
// 	// vars->light->d_point;
	
	
// }






void	raytrace(t_vars *vars, t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	t_vect		*ray;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;
	int			color;
	float		dist;

	vplane = get_view_plane(WIDTH, HEIGHT, vars->camera->fov);
	y_angle = HEIGHT / 2;
	while (y_angle >= (HEIGHT / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		vars->x = 0;
		while (x_angle <= (WIDTH / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vect_normalize(ray);
			
			if (intersect(vars->camera, ray, vars->sph))
				color = 167772215;
			else
				color = 0;
			my_mlx_pixel_put(vars->mlx, vars->x, vars->y, color);
			free(ray);
			vars->x++;
			x_angle++;
		}
		y_angle--;
		vars->y++;
	}
}

t_vplane	*get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		return (NULL);
	aspect_ratio = width / height;
	vplane->width = 1;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}