#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene{
	t_camera	*cams;
	t_sphere	*sphere;
	float		width;
	float		hight;
}				t_scene;


t_scene		*new_scene(t_camera *cam, t_sphere *sphere);

#endif