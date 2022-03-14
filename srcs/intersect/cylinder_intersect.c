#include "minirt.h"

// ray = D
// x = vec_subtraction(cam->d_origin, cyl->d_coordinates);
// v = cyl->nv_orientation

/*
   a   = D|D - (D|V)^2
   b/2 = D|X - (D|V)*(X|V)
   c   = X|X - (X|V)^2 - r*r
   P = O + D*t
*/

t_vec	*cyl_normal(t_vec *point, t_cyl *cyl)
{
	t_vec	*norm;
	t_vec	*p_on_axis;
	float	*len;

	len = dot_product(cyl->nv_orientation, point);
	p_on_axis = new_vector(cyl->d_coordinates->x, cyl->d_coordinates->y, cyl->d_coordinates->z);
	vect_multipl_on(p_on_axis, len);
	p_on_axis = vec_sum(p_on_axis, cyl->d_coordinates);
	norm = vec_subtraction(p_on_axis, point);
	vect_normalize(norm);
	return (norm);
}



float	cylinder_intersect(t_vec *ray_origin, t_vec *ray, t_cyl *cyl)
{
	t_vect	*camera_cy;
	float	abc[3];
	float	dist[2];
	float	discr;
	float	tmp;
	t_vect	*p;
	float	len;
	
	camera_cy = vec_subtraction(ray_origin, cyl->d_coordinates);
	// print_vect(cam->d_origin, "cam->d_origin");
	// print_vect(cyl->d_coordinates, "cyl->d_coordinates");
	// printf("co = %f\n", dot_product(camera_cy, camera_cy));
	tmp = dot_product(ray, cyl->nv_orientation);

	abc[0] = ((tmp * tmp) - 1);
	abc[1] = 2 * ((tmp * dot_product(camera_cy, cyl->nv_orientation)) - dot_product(ray, camera_cy));
	tmp = dot_product(cyl->nv_orientation, camera_cy);
	abc[2] = (tmp * tmp) + (powf(cyl->diam * 0.5, 2) - dot_product(camera_cy, camera_cy));

	free(camera_cy);
	discr = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
	// printf("b = %f, a = %f, c = %f\n", b, a, c);
	// printf("discr = %f\n", discr);
	if (discr < 0)
		return (-1);
	dist[0] = (((abc[1] * -1) - sqrt(discr)) / 2 * abc[0]);
	dist[1] = (((abc[1] * -1) + sqrt(discr)) / 2 * abc[0]);
	p = get_point(ray_origin, dist[0], ray);
	len = dot_product(cyl->nv_orientation, p);
	// printf("len == %f\n", len);
	if (len >= cyl->height / 2 || len  * -1 >= cyl->height / 2)
		return (-1);
	if(dist[0] > 0)
		return (dist[0]);
	return (-1);
}
