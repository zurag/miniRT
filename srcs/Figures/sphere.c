#include "miniRT.h"

// Может зависеть от радиуса и диаметра
t_sph	*new_sphere(void)
{
	t_sph *sph;

	sph = (t_sph *)malloc(sizeof(t_sph));
	sph->id = ft_strdup("sp");
	sph->center = new_vector(0.0, 0.0, 0.0);
	sph->diam = 0.0;
	sph->red = 0;
	sph->green = 0;
	sph->blue = 0;
	return (sph);
}