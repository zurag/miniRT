#include "miniRT.h"

t_scene		*new_scene(t_camera *cam, t_sph *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		error_exit(-1);
	scene->cams = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}
