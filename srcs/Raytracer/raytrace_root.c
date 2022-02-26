/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	raytrace(t_vars *vars, t_scene *scene)
{
	float		x_angle;
	float		y_angle;
	t_vect		*ray;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;
	int			color;

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
			if (sphere_intersect(vars->camera, ray, vars->sph))
				color = 167772215 * (vars->amb->l_rat + m(скаляр от вектора));
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
//	float		x;

//	fov = 1;
//	x = 2 * tag((double)fov / 2);
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		return (NULL);
	aspect_ratio = width * pow(height, (-1));
	vplane->width = 2 * tan((double)fov * 0.5);
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}