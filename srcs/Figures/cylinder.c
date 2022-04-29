/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:25:31 by acollin           #+#    #+#             */
/*   Updated: 2022/04/29 17:32:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_cylinder(t_cyl *cyl)
{
	if (cyl)
	{
		if (cyl->id)
			free(cyl->id);
		if (cyl->d_coordinates)
			free(cyl->d_coordinates);
		if (cyl->nv_orientation)
			free(cyl->nv_orientation);
		free(cyl);
	}
}

t_cyl	*new_cylinder(void)
{
	t_cyl	*cyl;

	cyl = (t_cyl *)malloc(sizeof(t_cyl));
	cyl->id = ft_strdup("cy");
	cyl->d_coordinates = vec_new(0.0, 0.0, 0.0);
	cyl->nv_orientation = vec_new(0.0, 0.0, 0.0);
	cyl->diam = 0.0;
	cyl->height = 0.0;
	cyl->color = 0;
	cyl->red = 0;
	cyl->green = 0;
	cyl->blue = 0;
	cyl->norm_flag = 0;
	return (cyl);
}
