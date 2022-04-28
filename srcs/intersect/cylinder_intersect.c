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

# define ABS(a)((a)>(0))?(a):(-a)



// m = D|V*t + X|V
// N = nrm( P-C-V*m )

t_vec	*cyl_normal(t_vec *point, t_cyl *cyl, float dist, t_vec *ray, t_vec *ray_origin)
{
	// (void)dist;
	// (void)ray;
	// t_vec	*p_on_axis;
	// t_vec	*ap;
	// t_vec	*tau;
	// t_vec	*sigma;
	// // float	cos_alpha;

	// p_on_axis = vec_subtraction(ray_origin, point);
	// ap = vec_subtraction(cyl->d_coordinates, p_on_axis);
	// vec_normalize(ap);
	// tau = cross_product(cyl->nv_orientation, ap);
	// sigma = cross_product(cyl->nv_orientation, tau);
	// vec_normalize(sigma);
	// // vec_normalize(p_on_axis);
	// // cos_alpha = dot_product(sigma, cyl->nv_orientation);
	// vec_mult(sigma, -1);
	// free(p_on_axis);
	// free(ap);
	// free(tau);
	// return (sigma);



	float m;
	t_vec *n;
	float t = dist;
	t_vec *D = ray;
	t_vec *tmp;
	t_vec *V = cyl->nv_orientation;
	t_vec *X = vec_subtraction(ray_origin, cyl->d_coordinates);

	m = dot_product(D, V) * t + dot_product(X, V); 
	V = vec_mult(cyl->nv_orientation, m);
	tmp = vec_subtraction(point, cyl->d_coordinates);
	n = vec_subtraction(tmp, V);
	vec_normalize(V);
	return (n);
}

float	cylinder_intersect(t_vec *ray_origin, t_vec *ray, t_cyl *cyl)
{
	t_vec *D;
	t_vec *X;
	t_vec *V;

	D = ray;
	X = vec_subtraction(ray_origin, cyl->d_coordinates);
	V = cyl->nv_orientation;

	float D_D = dot_product(D, D);
	float D_V = dot_product(D, V);
	float D_X = dot_product (D, X);
	float X_V = dot_product(X, V);
	float X_X = dot_product(X, X);

	float a, b, c, m0, m1;
	float discr;
	float dist1;
	float dist2;
	float inv_dist1;
	float inv_dist2;

	inv_dist1 = 0;
	inv_dist2 = 0;
	a = D_D - powf(D_V, 2);
	b = 2 * (D_X - (D_V * X_V));
	c = X_X - powf(X_V, 2) - powf(cyl->diam/2, 2);
	
	discr = (b * b) - (4 * c * a);
	if (discr < 0.02)
		return (-1);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / (2 * a));   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / (2 * a));
	m0 = D_V * dist1 + X_V;
	m1 = D_V * dist2 + X_V;
	// P = get_point(ray_origin, dist1, ray);
	// vec_mult(V, m);
	// N = vec_normalize(vec_subtraction(vec_subtraction(P, C), V));	// на всякий случай.
	 if (!cyl_flag)
	 {
	 	if (ABS(m0) >= cyl->height)
	 	{
	 		inv_dist1 = dist1;
	 		dist1 = -1;
	 	}
	 	if (ABS(m1) >= cyl->height)
	 	{
	 		inv_dist2 = dist2;
	 		dist2 = -1;
	 	}
	 }
	if (dist1 < 0.02 && dist2 < 0.02)
		return (-1);
	if (dist1 > 0.02 && dist2 > 0.02)
	{
		if (dist1 < dist2)
			return (dist1);
		return (dist2);
	}
	if (dist1 > 0.02 || dist2 > 0.02)
	{
		if (dist1 > 0.02)
			return (dist1);
		return (dist2);
	}
	return (-1);
}
