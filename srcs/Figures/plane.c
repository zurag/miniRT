#include "miniRT.h"

t_plane	*new_plane(void)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->id = ft_strdup("pl");
	plane->d_coordinates = new_vector(0.0, 0.0, 0.0);
	plane->nv_orientation = new_vector(0.0, 0.0, 0.0);
	plane->red = 0;
	plane->green = 0;
	plane->blue = 0;
	return (plane);
}
