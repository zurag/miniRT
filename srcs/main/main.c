/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:28:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_scene	*scene;

	(void)argv;
	init(&vars);
	if (argc > 1)
		parser(argv, &vars);
//	printf("Just check = %f\n", vars.cyl->height);
	scene = new_scene(vars.camera, vars.sph);

	raytrace(&vars, scene);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 1, 1);
	free_scene(scene);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, 0);
	mlx_loop(vars.mlx);
	return (0);
}
