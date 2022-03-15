#include "minirt.h"

float	plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;

	denom = dot_product(plane->nv_orientation, ray);
	// printf("denom == %f\n", denom);
	if (denom >= EPSILON)
	{
		p0lo = vec_subtraction(plane->d_coordinates, ray_origin);
		dist = dot_product(p0lo, plane->nv_orientation) / denom;
		if (dist >= EPSILON)
		{
//			printf("HERE\n");
			free(p0lo);
			return (dist);
		}
		free(p0lo);
	}
	return(-1);
}
