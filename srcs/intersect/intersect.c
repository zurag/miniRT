
#include "minirt.h"

float	plane_intersect(t_camera *cam, t_vec *ray, t_plane *plane)
{
	float	denom;
	float	dist;
	t_vec	*p0lo;

	denom = dot_product(ray, plane->nv_orientation);
	if (!denom)
		return (0);
	p0lo = vec_subtraction(cam->d_origin, plane->d_coordinates);
	dist = dot_product(p0lo, plane->d_coordinates) / denom;
	free(p0lo);
	return(dist);
}

float	sphere_intersect(t_camera *cam, t_vec *ray, t_sph *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist1; // ближняя дистанция
	float	dist2; // дальняя точка пересечения
	t_vec	*cam_sphere;

	dist1 = 0;
	dist2 = 0;
	b = 0;
	c = 0;
	cam_sphere = vec_subtraction(cam->d_origin, sphere->center);
	b = 2 * (dot_product(cam_sphere, ray));
	c = dot_product(cam_sphere, cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / (2));   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / (2));		// на всякий случай.
//	 printf("dist1 == %f dist2 == %f\n", dist1, dist2);
	if (dist1 > 0)
		return (dist1);
//	t_vec	*hit_position = vect_multipl_on(ray, dist1); // точка
//	соприкосновения
	return (0.0);
}

// ray = D
// x = vec_subtraction(cam->d_origin, cyl->d_coordinates);


float cylinder_intersect(t_camera *cam, t_vec *ray, t_cyl *cyl)
{
	// t_vec	*start;
	// t_vec	*end;
	t_vec	*camera_cy;
	float	a;
	float	b;
	float	c;
	float	dist[4];
	float	discr;
	float	tmp;
	float	m[2];


	camera_cy = vec_subtraction(cam->d_origin, cyl->d_coordinates);
	tmp = dot_product(ray, cyl->nv_orientation);
	a = dot_product(ray, ray) + (tmp * tmp);
	b = 2 * (dot_product(ray, cyl->nv_orientation) -  (dot_product(ray, cyl->nv_orientation) * dot_product(camera_cy, cyl->nv_orientation)));
	// tmp = dot_product(ray, cyl->nv_orientation);
	c = dot_product(camera_cy, camera_cy) - (tmp * tmp) - (cyl->diam / 2 * cyl->diam / 2);
	free(camera_cy);
	discr = (b * b) - (4 * a * c);
	printf("discr = %f\n", discr);
	dist[0] = (((b * -1) - sqrt(discr)) / 2);
	dist[1] = (((b * -1) + sqrt(discr)) / 2);
	m[0] = (dot_product(ray, cyl->nv_orientation) * dist[0]) + dot_product(camera_cy, cyl->nv_orientation);
	m[1] = (dot_product(ray, cyl->nv_orientation) * dist[1]) + dot_product(camera_cy, cyl->nv_orientation);
//	printf("dist1== %f, dist2== %f\n", dist[0], dist[1]);
	// start = cyl->
	if(dist[0] > 0)
		return (dist[0]);
	return (0);
}
//
//float a = ray.getDirection().x*ray.getDirection().x + ray.getDirection().z*ray.getDirection().z;
//    float b = 2*(ray.getOrigin().x*ray.getDirection().x + ray.getOrigin().z*ray.getDirection().z);
//    float c = ray.getOrigin().x*ray.getOrigin().x + ray.getOrigin().z*ray.getOrigin().z - m_radius*m_radius;