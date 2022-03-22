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

t_vec	*cyl_normal(t_vec *point, t_cyl *cyl, float dist, t_vec *ray, t_vec *ray_origin)
{
	(void)ray;
	(void)ray_origin;
	(void)dist;
	t_vec	*norm;
	t_vec	*p_on_axis;
	float	len;

	len = dot_product(cyl->nv_orientation, point);
	p_on_axis = vec_new(cyl->d_coordinates->x, cyl->d_coordinates->y,
					 cyl->d_coordinates->z);
	vec_mult(p_on_axis, len);
	p_on_axis = vec_sum(p_on_axis, cyl->d_coordinates);
	norm = vec_subtraction(point, p_on_axis);
	vec_normalize(norm);
	free(p_on_axis);

	// m = D|V*t + X|V
	// N = nrm( P-C-V*m )


	// float m;

	// float D_V;
	// float X_V;
	// t_vec	*norm;
	// t_vec *D = ray;

	// t_vec *X = vec_subtraction(ray_origin, cyl->d_coordinates);;
	// t_vec *V = cyl->nv_orientation;
	// t_vec *C = cyl->d_coordinates;

	// D_V = dot_product(D, V);
	// X_V = dot_product(X, V);

	// m = D_V * dist + X_V;
	// vec_mult(V, m);
	// norm = vec_subtraction(vec_subtraction(point, C), V);
	// vec_normalize(V);
	// vec_normalize(norm);
	return (norm);
}

float	cylinder_intersect(t_vec *ray_origin, t_vec *ray, t_cyl *cyl)
{
	// t_vec	*camera_cy;
	// float	abc[3];
	// float	dist[2];
	// float	discr;
	// float	tmp;
	// t_vec	*p0;
	// t_vec	*p1;
	
	// float	len[2];
	
	// camera_cy = vec_subtraction(ray_origin, cyl->d_coordinates);
	// tmp = dot_product(ray, cyl->nv_orientation);
	// abc[0] = ((tmp * tmp) - 1);
	// abc[1] = 2 * ((tmp * dot_product(camera_cy, cyl->nv_orientation)) - dot_product(ray, camera_cy));
	// tmp = dot_product(cyl->nv_orientation, camera_cy);
	// abc[2] = (tmp * tmp) + (powf(cyl->diam * 0.5, 2) - dot_product(camera_cy, camera_cy));
	// // free(camera_cy);
	// discr = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
	// if (discr < 0)
	// {
	// 	free(camera_cy);
	// 	return (-1);
	// }
	// dist[0] = (((abc[1] * -1) - sqrt(discr)) / 2 * abc[0]);
	// dist[1] = (((abc[1] * -1) + sqrt(discr)) / 2 * abc[0]);
	// if (dist[0] < EPSILON && dist[1] < EPSILON)
	// {
	// 	free(camera_cy);
	// 	return (-1);
	// }



	// p0 = get_point(ray_origin, dist[0], ray);
	// p1 = get_point(ray_origin, dist[1], ray);
	// len[0] = dot_product(cyl->nv_orientation, p0);
	// len[1] = dot_product(cyl->nv_orientation, p1);
	// free(p0);
	// free(p1);





	//TODO: HUGEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
// ray = D
// x = vec_subtraction(cam->d_origin, cyl->d_coordinates);
// v = cyl->nv_orientation

/*
   a   = D|D - (D|V)^2
   b/2 = D|X - (D|V)*(X|V)
   c   = X|X - (X|V)^2 - r*r
   P = O + D*t

	m = D|V*t + X|V
   N = nrm( P-C-V*m )
*/

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

// обратно
	// float D_D = dot_product(D, D);
//	 float D_V = dot_product(V, D);
//	float D_X = dot_product (X, D);
//	 float X_V = dot_product(V, X);
	// float X_X = dot_product(X, X);


	float a, b, c, m0, m1;
	float discr;
	float dist1;
	float dist2;
	// t_vec	*N;
	// t_vec	*P;

	// x = camera_cy    tmp = (D|V)

	a = D_D - powf(D_V, 2);
	b = 2 * (D_X - (D_V * X_V));
	c = X_X - powf(X_V, 2) - powf(cyl->diam/2, 2);
	
	discr = (b * b) - (4 * c * a);
	if (discr < 0)
		return (-1);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / (2 * a));   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / (2 * a));
	m0 = D_V * dist1 + X_V;
	m1 = D_V * dist2 + X_V;
	// P = get_point(ray_origin, dist1, ray);
	// vec_mult(V, m);
	// N = vec_normalize(vec_subtraction(vec_subtraction(P, C), V));	// на всякий случай.
	
	if (ABS(m0) >= cyl->height / 2)
		dist1 = -1;
	if (ABS(m1) >= cyl->height / 2)
		dist2 = -1;

	if (dist1 < 0 && dist2 < 0)
		return (-1);
	if (dist1 > 0 && dist2 > 0)
	{
		if (dist1 < dist2)
			return (dist1);
		return (dist2);
	}
	if (dist1 > 0 || dist2 > 0)
	{
		if (dist1 > 0)
			return (dist1);
		return (dist2);
	}
	return (-1);



// Version main


	// if (dist1 > 0)	
	// {
	// 	// vec_normalize(V);
	// 	// printf("dist1 == %f\n", dist1);
	// 	return (dist1);
	// }
	// // vec_normalize(V);
	// return (-1);


	// tmp = dot_product(camera_cy, cyl->nv_orientation);
	// p0 = vec_new(ray->x * dist[0], ray->y * dist[0], ray->z * dist[0]);
	// p1 = vec_new(ray->x * dist[1], ray->y * dist[1], ray->z * dist[1]);
	// len[0] = dot_product(cyl->nv_orientation, p0) + tmp;
	// len[1] = dot_product(cyl->nv_orientation, p1) + tmp;
	// free(p0);
	// free(p1);




	// vec_mult(cyl->nv_orientation, dist[0]);
	// tmp = dot_product(ray, cyl->nv_orientation);
	// vec_normalize(cyl->nv_orientation);
	// len[0] = dot_product(camera_cy,cyl->nv_orientation) + tmp;
	// vec_mult(cyl->nv_orientation, dist[1]);
	// tmp = dot_product(ray, cyl->nv_orientation);
	// vec_normalize(cyl->nv_orientation);
	// len[1] = dot_product(camera_cy,cyl->nv_orientation) + tmp;
	// free(p0);
	// free(p1);


	// if (len[0] < 0)
	// 	len[0] *= -1;
	// if (len[1] < 0)
	// 	len[1] *= -1;

	// printf("len1= %f, len2 = %f\n", len[0], len[1]);
	// if (len[0] > cyl->height / 2 || len[0]  * -1 > cyl->height / 2)
	// 	dist[0] = -1;
	// if (len[1] > cyl->height / 2 || len[1]  * -1 > cyl->height / 2)
	// 	dist[1] = -1;
	
	// if (ABS(len[0]) >= cyl->height / 2)
	// 	dist[0] = -1;
	// if (ABS(len[1]) >= cyl->height / 2)
	// 	dist[1] = -1;


	
	// if (dist[0] == -1 && dist[1] == -1)
	// 	return (-1);
	// else if (dist[0] > 0 && dist[1] > 0)
	// {
	// 	if (dist[0] > dist[1])
	// 		return (dist[1]);
	// 	return (dist[0]);
	// }
	// else if (dist[0] > 0 || dist[1] > 0)
	// {
	// 	if (dist[1] < 0)
	// 		return (dist[0]);
	// 	return (dist[1]);
	// }

	// if (len >= cyl->height / 2 || len  * -1 >= cyl->height / 2)
	// 	return (-1);
	
	// if(dist[0] > 0)
	// 	return (dist[0]);
	return (-1);
}
