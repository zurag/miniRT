#ifndef CAMERA_H
# define CAMERA_H

typedef struct	s_camera{
	t_vect		*origin;
	t_vect		*direction;
	float		fov;
}				t_camera;

t_camera *new_camera(t_vect *origin, t_vect *direction, float fov);

#endif