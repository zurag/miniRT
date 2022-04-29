/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:54:12 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 13:54:55 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*sph_normal(t_vec *point, t_sph *sph)
{
	t_vec	*norm;

	norm = vec_subtraction(point, sph->center);
	vec_normalize(norm);
	return (norm);
}

float	sphere_intersect(t_vec *ray_origin, t_vec *ray, t_sph *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist[2];
	t_vec	*cam_sphere;

	dist[0] = 0;
	dist[1] = 0;
	b = 0;
	c = 0;
	cam_sphere = vec_subtraction(ray_origin, sphere->center);
	b = 2 * (dot_product(cam_sphere, ray));
	c = dot_product(cam_sphere, cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (-1);
	dist[0] = (((b * -1) - sqrt(discr)) / (2));
	dist[1] = (((b * -1) + sqrt(discr)) / (2));
	if (dist[0] > 0.02)
		return (dist[0]);
	return (-1);
}
