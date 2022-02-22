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


#include "miniRT.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_vars	vars;
	t_data	img;
//	char	*str;
//	double d = 0.0;



	init(&vars);
	if (argc > 1)
	{
		parser(argv, &vars);
//		process_drawing()
	}
	raytrace(var)
	printf("Just check = %f\n", vars.cyl->height);
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
//	else
//	{
//		write(1, &"Wrong input! Change something", 29);
//		exit(0);
//	}
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, 0);
	mlx_loop(vars.mlx);
	return (0);
}
