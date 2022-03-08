#include "miniRT.h"

t_cyl	*new_cylinder(void)
{
	t_cyl *cyl;

	cyl = (t_cyl *)malloc(sizeof(t_cyl));
	cyl->id = ft_strdup("cy");
	cyl->d_coordinates = new_vector(0.0, 0.0, 0.0);
	cyl->nv_orientation = new_vector(0.0, 0.0, 0.0);
	cyl->diam = 0.0;
	cyl->height = 0.0;
	cyl->red = 0;
	cyl->green = 0;
	cyl->blue = 0;
	return (cyl);
}