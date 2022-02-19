#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct	s_vplane{
	float	width;
	float	hight;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

t_vplane	*get_view_plane(float width, float hight, float fov);
void	ray_tracing(void *mlx, void *wind, t_scene *scene);

#endif
