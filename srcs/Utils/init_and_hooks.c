/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:46:57 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	vars->x = 0;
	vars->y = 0;
	vars->img = malloc(sizeof(t_data));
	vars->amb = new_amb();
	vars->camera = new_camera();
	vars->light = NULL;
	vars->figure = NULL;
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &(vars->img->bpp),
			&(vars->img->line_len), &(vars->img->endian));
}

void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
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
	if (keycode == ARROW_LEFT)
		vars->camera->d_origin->x = vars->camera->d_origin->x - 1;
	if (keycode == ARROW_RIGHT)
		vars->camera->d_origin->x = vars->camera->d_origin->x + 1;
	if (keycode == ARROW_UP)
		vars->camera->d_origin->y = vars->camera->d_origin->y + 1;
	if (keycode == ARROW_DOWN)
		vars->camera->d_origin->y = vars->camera->d_origin->y - 1;
	raytrace(vars, &vars->figure);
	return (0);
}

int	close_win(int keycode)
{
	(void)keycode;
	exit(0);
}
