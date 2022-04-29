#include "minirt.h"

static float	ft_abs(float value)
{
	if (value > 0)
		return (value);
	return (-value);
}

t_vec	*cyl_normal(t_vec *point, t_cyl *cyl,
		float dist, t_vec *ray, t_vec *ray_origin)
{
	float	m;
	t_vec	*n;
	t_vec	*tmp;
	t_vec	*x;

	x = vec_subtraction(ray_origin, cyl->d_coordinates);
	m = dot_product(ray, cyl->nv_orientation) * dist \
		+ dot_product(x, cyl->nv_orientation);
	vec_mult_on(cyl->nv_orientation, m);
	tmp = vec_subtraction(point, cyl->d_coordinates);
	n = vec_subtraction(tmp, cyl->nv_orientation);
	vec_normalize(cyl->nv_orientation);
	free(x);
	free(tmp);
	if (norm_flag)
	{
		vec_mult_on(n, -1);
		norm_flag = 0;
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
		norm_flag = 1;
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
	float	d_v;
	float	x_v;
	float	abc[3];
	float	m[2];
	float	discr;
	float	dist[2];

	x = vec_subtraction(ray_origin, cyl->d_coordinates);
	d_v = dot_product(ray, cyl->nv_orientation);
	x_v = dot_product(x, cyl->nv_orientation);
	abc[0] = dot_product(ray, ray) - powf(d_v, 2);
	abc[1] = 2 * (dot_product (ray, x) - (d_v * x_v));
	abc[2] = dot_product(x, x) - powf(x_v, 2) - powf(cyl->diam / 2, 2);
	discr = (abc[1] * abc[1]) - (4 * abc[2] * abc[0]);
	free(x);
	if (discr < 0.02)
		return (-1);
	dist[0] = (((abc[1] * -1) - sqrt(discr)) / (2 * abc[0]));
	dist[1] = (((abc[1] * -1) + sqrt(discr)) / (2 * abc[0]));
	m[0] = d_v * dist[0] + x_v;
	m[1] = d_v * dist[1] + x_v;
	return (ft_dist(m, dist, cyl, 0));
}
