#include "miniRT.h"

t_camera	*new_camera(void)
{
	t_camera *camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		error_exit(-1);
	camera->id = ft_strdup("C");
	camera->d_origin = new_vector(0.0, 0.0, 0.0);
	camera->nv_direction = new_vector(0.0, 0.0, 0.0);
	camera->fov = 0;
	return (camera);
}