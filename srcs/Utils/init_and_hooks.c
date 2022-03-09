/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/09 20:37:02 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	vars->x = 0;
	vars->y = 0;
	vars->img = NULL;
	vars->amb = init_amb();
	vars->camera = init_camera();
	vars->light = init_light();
	vars->plane = init_plane();
	vars->sph = init_sph();
	vars->cyl = init_cyl();
}

t_amb	*init_amb(void)
{
	t_amb *amb;

	amb = (t_amb *)malloc(sizeof(t_amb));
	amb->id = ft_strdup("A");
	amb->light_ratio = 0.0;
	amb->red = 0;
	amb->green = 0;
	amb->blue = 0;
	return (amb);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_win(int keycode)
{
	(void)keycode;
	exit(0);
}
