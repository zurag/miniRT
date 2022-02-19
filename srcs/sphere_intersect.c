#include "../includes/minirt.h"

int	sphere_intersect(t_camera *cam, t_vect *ray, t_sphere *sphere)
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
		return (1);
	return (0);
}
