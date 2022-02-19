/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/19 13:33:37 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



void	print_vect(t_vect *vec, char *name)
{
	printf("%s : x== %f, y == %f, z == %f\n", name, vec->x, vec->y, vec->z);
}



int	main()
{
	void	*mlx;
	void	*wind;

	mlx = mlx_init();
	t_vect	*sphere_center = new_vector(3, 2, -32);
	t_sphere	*sphere = new_sphere(sphere_center, 12/2);
	t_vect	*cam_origin = new_vector(0, 0, 0);
	t_vect	*cam_direction = new_vector(0, 0, -1);
	t_camera	*cam = new_camera(cam_origin, cam_direction, 70);
	t_scene	*scene = new_scene(cam, sphere);
	scene->width = 800;
	scene->hight = 600;
	wind = mlx_new_window(mlx, scene->width, scene->hight, "test");
	ray_tracing(mlx, wind, scene);
	free(scene);
	mlx_loop(mlx);

	// printf("%f", dot_product(new_vector(0, 0, 1), new_vector(0, 0, -1)));
	return (0);
}
