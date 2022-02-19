#include "../includes/minirt.h"

t_scene		*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->cams = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->hight = 0;
	return (scene);
}
