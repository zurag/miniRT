/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:25:49 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:25:52 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_plane(t_plane *plane)
{
	if (plane)
	{
		if (plane->id)
			free(plane->id);
		if (plane->d_coordinates)
			free(plane->d_coordinates);
		if (plane->nv_orientation)
			free(plane->nv_orientation);
		free(plane);
	}
}

t_plane	*new_plane(void)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->id = ft_strdup("pl");
	plane->d_coordinates = vec_new(0.0, 0.0, 0.0);
	plane->nv_orientation = vec_new(0.0, 0.0, 0.0);
	plane->color = 0;
	plane->red = 0;
	plane->green = 0;
	plane->blue = 0;
	return (plane);
}
