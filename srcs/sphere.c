#include "../includes/minirt.h"

t_sphere	*new_sphere(t_vect *center, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}
