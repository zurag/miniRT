#include "minirt.h"

float	plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;

	denom = dot_product(ray, plane->nv_orientation);
	// printf("denom == %f\n", denom);
	if (denom >= EPSILON)
	{
		// printf("HERE\n");
		p0lo = vec_subtraction(ray_origin, plane->d_coordinates);
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
