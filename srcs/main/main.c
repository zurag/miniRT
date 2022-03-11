/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
<<<<<<< HEAD:srcs/main/main.c
/*   Updated: 2022/03/08 19:28:56 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
=======
/*   Updated: 2022/03/09 20:38:04 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"
>>>>>>> miniRT/zurag:srcs/main.c

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_scene	*scene;

	(void)argv;
	init(&vars);
	if (argc > 1)
		parser(argv, &vars);
<<<<<<< HEAD:srcs/main/main.c
//	printf("Just check = %f\n", vars.cyl->height);
	scene = new_scene(vars.camera, vars.sph);

	raytrace(&vars, scene);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 1, 1);
	free_scene(scene);
=======
//		process_drawing()
	}
	raytrace(vars)
	printf("Just check = %f\n", vars.cyl->height);
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	else
//	{
//		write(1, &"Wrong input! Change something", 29);
//		exit(0);
//	}
>>>>>>> miniRT/zurag:srcs/main.c
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, 0);
	mlx_loop(vars.mlx);
	return (0);
}
