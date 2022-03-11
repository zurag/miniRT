/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/08 19:28:04 by acollin          ###   ########.fr       */
=======
/*   Updated: 2022/03/09 20:36:49 by zurag            ###   ########.fr       */
>>>>>>> miniRT/zurag
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
			ray = new_vector(x_ray, y_ray, -1);
			vect_normalize(ray);
<<<<<<< HEAD
			if (sphere_intersect(vars->camera, ray, vars->sph))
=======
			
			if (intersect(vars->camera, ray, vars->sph))
>>>>>>> miniRT/zurag
				color = 167772215;
			else
				color = 0;
//			printf("checkk in ray trace\n");
			printf("color = %d\n", color);
			ft_mlx_pixel_put(vars->img, vars->x, vars->y, color);
			// break;
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
	vplane->width = 2 * tan((double)fov * 0.5 );
//	vplane->width = 1;
	vplane->height = vplane->width * pow(aspect_ratio, -1);
	vplane->x_pixel = vplane->width * pow(width, -1);
	vplane->y_pixel = vplane->height * pow(height, -1);
	return (vplane);
}
