/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:47:06 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:18:31 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;

	denom = dot_product(plane->nv_orientation, ray);
	if (denom < 0.02)
	{
		vec_mult_on(plane->nv_orientation, -1);
		denom *= -1;
	}
	if (denom > 0.02)
	{
		p0lo = vec_subtraction(plane->d_coordinates, ray_origin);
		dist = dot_product(p0lo, plane->nv_orientation) / denom;
		free(p0lo);
		if (dist >= 0.02)
			return (dist);
	}
	return (-1);
}
