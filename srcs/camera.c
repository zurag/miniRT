#include "../includes/minirt.h"

t_camera *new_camera(t_vect *origin, t_vect *direction, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->origin = origin;
	cam->direction = direction;
	cam->fov = fov;
	return (cam);
}
