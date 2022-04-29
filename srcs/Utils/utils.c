/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 15:37:59 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_exit(int code)
{
	if (code == -1)
		write(STDERR_FILENO, "Error: Can't allocate memory for new "
			"element\n", 46);
	exit(code);
}

t_ray	*init_ray(t_vec *dir, t_vec *orig)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->dir = dir;
	ray->orig = orig;
	return (ray);
}
