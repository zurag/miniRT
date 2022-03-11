/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:26:17 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:26:19 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_sphere(t_sph *sphere)
{
	if (sphere)
	{
		if (sphere->id)
			free(sphere->id);
		if (sphere->center)
			free(sphere->center);
		free(sphere);
	}
}

// Может зависеть от радиуса и диаметра
t_sph	*new_sphere(void)
{
	t_sph	*sph;

	sph = (t_sph *)malloc(sizeof(t_sph));
	sph->id = ft_strdup("sp");
	sph->center = new_vector(0.0, 0.0, 0.0);
	sph->diam = 0.0;
	sph->rad = 0.0;
	sph->red = 0;
	sph->green = 0;
	sph->blue = 0;
	return (sph);
}
