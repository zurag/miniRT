#include "minirt.h"

float	plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;

	denom = dot_product(plane->nv_orientation, ray);
	if (denom < EPSILON)
	{
		vec_mult(plane->nv_orientation, -1);
		denom *= -1;
	}
	if (denom > EPSILON)
	{
		p0lo = vec_subtraction(plane->d_coordinates, ray_origin);
		dist = dot_product(p0lo, plane->nv_orientation) / denom;
		if (dist >= EPSILON)
		{
			free(p0lo);
			return (dist);
		}
		free(p0lo);
	}
	return(-1);
}
