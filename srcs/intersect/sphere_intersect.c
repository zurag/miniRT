#include "minirt.h"

t_vec	*sph_normal(t_vec *point, t_sph *sph)
{
	t_vec	*norm;

	norm = vec_subtraction(point, sph->center);
	vec_normalize(norm);
	return (norm); 
}


float	sphere_intersect(t_vec *ray_origin, t_vec *ray, t_sph *sphere)
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
	// printf("SPHERE INTER\n");
	
	// print_vect(sphere->center, "sphere->center");
	cam_sphere = vec_subtraction(ray_origin, sphere->center);
	b = 2 * (dot_product(cam_sphere, ray));
	c = dot_product(cam_sphere, cam_sphere) - (sphere->rad * sphere->rad);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (-1);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / (2));   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / (2));		// на всякий случай.
	// printf("dist1 == %f dist2 == %f\n", dist1, dist2);
	if (dist1 > 0)
	{
		// printf("dist1 == %f\n", dist1);
		return (dist1);
	}
//	t_vec	*hit_position = vect_multipl_on(ray, dist1); // точка
//	соприкосновения
	return (-1);
}
