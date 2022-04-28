#include "minirt.h"

float	plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;
	t_vec	*nv_new;

	denom = dot_product(plane->nv_orientation, ray);
	nv_new = plane->nv_orientation;
	if (denom < EPSILON)
	{
		nv_new = vec_mult(plane->nv_orientation, -1);
		denom *= -1;
	}
	if (denom > EPSILON)
	{
		p0lo = vec_subtraction(plane->d_coordinates, ray_origin);
//		printf("check\n");
		dist = dot_product(p0lo, nv_new) / denom;
		if (dist >= EPSILON)
		{
			free(p0lo);
			return (dist);
		}
		free(p0lo);
	}
	return(-1);
}
