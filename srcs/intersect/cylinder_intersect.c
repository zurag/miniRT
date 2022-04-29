/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:48:18 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:33:44 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	ft_abs(float value)
{
	if (value > 0)
		return (value);
	return (-value);
}

t_vec	*cyl_normal(t_vec *point, t_cyl *cyl,
		float dist, t_ray *ray)
{
	float	m;
	t_vec	*n;
	t_vec	*tmp;
	t_vec	*x;

	x = vec_subtraction(ray->orig, cyl->d_coordinates);
	m = dot_product(ray->dir, cyl->nv_orientation) * dist \
		+ dot_product(x, cyl->nv_orientation);
	vec_mult_on(cyl->nv_orientation, m);
	tmp = vec_subtraction(point, cyl->d_coordinates);
	n = vec_subtraction(tmp, cyl->nv_orientation);
	vec_normalize(cyl->nv_orientation);
	free(x);
	free(tmp);
	if (cyl->norm_flag)
	{
		vec_mult_on(n, -1);
		cyl->norm_flag = 0;
	}
	return (n);
}

float	ft_dist(float m[2], float dist[2], t_cyl *cyl, float inv_dist)
{
	if (ft_abs(m[0]) >= cyl->height)
	{
		inv_dist = dist[0];
		dist[0] = -1;
	}
	if (ft_abs(m[1]) >= cyl->height)
		dist[1] = -1;
	if (inv_dist && dist[1] > 0.02)
		cyl->norm_flag = 1;
	if (dist[0] < 0.02 && dist[1] < 0.02)
		return (-1);
	if (dist[0] > 0.02 && dist[1] > 0.02)
	{
		if (dist[0] < dist[1])
			return (dist[0]);
		return (dist[1]);
	}
	if (dist[0] > 0.02 || dist[1] > 0.02)
	{
		if (dist[0] > 0.02)
			return (dist[0]);
		return (dist[1]);
	}
	return (-1);
}

float	cylinder_intersect(t_vec *ray_origin, t_vec *ray, t_cyl *cyl)
{
	t_vec	*x;
	float	dv_xv_dis[3];
	float	abc[3];
	float	m[2];
	float	dist[2];

	x = vec_subtraction(ray_origin, cyl->d_coordinates);
	dv_xv_dis[0] = dot_product(ray, cyl->nv_orientation);
	dv_xv_dis[1] = dot_product(x, cyl->nv_orientation);
	abc[0] = dot_product(ray, ray) - powf(dv_xv_dis[0], 2);
	abc[1] = 2 * (dot_product (ray, x) - (dv_xv_dis[0] * dv_xv_dis[1]));
	abc[2] = dot_product(x, x) - powf(dv_xv_dis[1], 2) - powf(cyl->diam / 2, 2);
	dv_xv_dis[2] = (abc[1] * abc[1]) - (4 * abc[2] * abc[0]);
	free(x);
	if (dv_xv_dis[2] < 0)
		return (-1);
	dist[0] = (((abc[1] * -1) - sqrt(dv_xv_dis[2])) / (2 * abc[0]));
	dist[1] = (((abc[1] * -1) + sqrt(dv_xv_dis[2])) / (2 * abc[0]));
	m[0] = dv_xv_dis[0] * dist[0] + dv_xv_dis[1];
	m[1] = dv_xv_dis[0] * dist[1] + dv_xv_dis[1];
	return (ft_dist(m, dist, cyl, 0));
}
