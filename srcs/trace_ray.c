#include "../includes/minirt.h"

void	ray_tracing(void *mlx, void *wind, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			color;
	t_vect		*ray;
	t_vplane	*vplane;
	float		y_ray;
	float		x_ray;

	mlx_y = 0;
	vplane = get_view_plane(scene->width, scene->hight, scene->cams->fov);
	y_angle = scene->hight / 2;
	while (y_angle >= (scene->hight / 2) * -1)
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * -1;
		mlx_x = 0;
		while (x_angle <= (scene->width / 2))
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			vect_normalize(ray);		
			if (sphere_intersect(scene->cams, ray, scene->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, wind, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			// printf("mlx_x = %d, mlx_y = %d\n", mlx_x, mlx_y);
			mlx_x++;
			// printf("width = %f x_angle = %f\n", scene->width, x_angle);
			// usleep(10000);
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane	*get_view_plane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;
	
	fov = 1;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		return (NULL);
	aspect_ratio =  width / hight;
	vplane->width = 1;
	vplane->hight = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->hight / hight;
	return (vplane);
}
