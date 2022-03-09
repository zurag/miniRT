
#include "minirt.h"

float	plane_intersect(t_camera *cam, t_vect *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vect	*p0lo;

	denom = dot_product(ray, plane->nv_orientation);
	if (!denom)
		return (0);
	p0lo = vec_subtraction(cam->d_origin, plane->d_coordinates);
	dist = dot_product(p0lo, plane->d_coordinates) / denom;
	free(p0l0);
	return(dist);
}


float	sphere_intersect(t_camera *cam, t_vect *ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist1;
	float	dist2;
	t_vect	*cam_sphere;


	dist1 = 0;
	dist2 = 0;
	b = 0;
	c = 0;
	cam_sphere = vec_subtraction(cam->origin, sphere->center);
	// a = dot_product(ray, ray);
	b = 2 * (dot_product(cam_sphere, ray));
	c = dot_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist1 = (((b * -1) - sqrt(discr)) / 2);
	dist2 = (((b * -1) + sqrt(discr)) / 2);
	// printf("dist1 == %f dist2 == %f\n", dist1, dist2);
	if (dist1 > 0)
		return (dist1);
	return (0);
}


// ray = D
// x = vec_subtraction(cam->d_origin, cyl->d_coordinates);


float cylinder_intersect(t_camera *cam, t_vect *ray, t_cyl *cyl)
{
	// t_vect	*start;
	// t_vect	*end;
	t_vect	*camera_cy;
	float	a;
	float	b;
	float	c;
	float	dist[4];
	float	discr;
	float	tmp;
	float	m[2];


	camera_cy = vec_subtraction(cam->d_origin, cyl->d_coordinates);
	tmp = dot_product(ray, cyl->nv_orientation);
	a = dot_product(ray, ray) - (tmp * tmp);
	b = 2 * (dot_product(ray, cyl->nv_orientation) -  (dot_product(ray, cyl->nv_orientation) * dot_product(camera_cy, cyl->nv_orientation)));
	// tmp = dot_product(ray, cyl->nv_orientation);
	c = dot_product(camera_cy, camera_cy) - (tmp * tmp) - (cyl->diam / 2 * cyl->diam / 2);
	free(camera_cy);
	discr = (b * b) - (4 * a * c);
	dist[0] = (((b * -1) - sqrt(discr)) / 2);
	dist[1] = (((b * -1) + sqrt(discr)) / 2);
	m[0] = (dot_product(ray, cyl->nv_orientation) * dist[0]) + dot_product(camera_cy, cyl->nv_orientation);
	m[1] = (dot_product(ray, cyl->nv_orientation) * dist[1]) + dot_product(camera_cy, cyl->nv_orientation);
	
	// start = cyl->
	if(dist[0] > 0)
		return (dist[0]);
	return (0);
}