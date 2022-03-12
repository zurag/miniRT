/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:20 by zurag             #+#    #+#             */
/*   Updated: 2022/03/09 20:43:59 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vector.h"
# include "sphere.h"
# include "camera.h"
# include "scene.h"
# include "view_plane.h"
# include "intersect.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

// Num of cores ( for PTHREAD )
# define CORES_NUM 4

// Window and keyboard
# define WIDTH 480
# define HEIGHT 360
# define ESC_KEY 53

//Colors
# define COL_ST 0x75E555
# define COL_FIN 0xE8811A
# define BLACK 0x000000

typedef struct s_data	t_data;
typedef struct s_vars	t_vars;
typedef struct s_amb	t_amb;
typedef struct s_camera	t_camera;
typedef struct s_light	t_light;
typedef struct s_sph	t_sph;
typedef struct s_cyl	t_cyl;
typedef struct s_plane	t_plane;

typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_data		*img;
	t_amb		*amb;
	t_camera	*camera;
	t_light		*light;
	t_plane		*plane;
	t_sph		*sph;
	t_cyl		*cyl;
}				t_vars;
//PARSING

typedef struct s_amb
{
	char		*id;
	float		l_rat;
	int			red;
	int			green;
	int			blue;
}				t_amb;

typedef struct s_camera
{
	char		*id;
	t_vect		*d_origin;
	t_vect		*nv_direction;
	int			fov;
}				t_camera;


typedef struct s_light
{
	char		*id;
	t_vect		*d_point;
	float		bright;
}				t_light;

typedef struct s_plane
{
	char		*id;
	t_vect		*d_coordinates;
	t_vect		*nv_orientation;
	int			red;
	int			green;
	int			blue;
}				t_plane;

typedef struct s_sph
{
	char		*id;
	t_vect		*center;
	float		diam;
	float		rad;
	int			red;
	int			green;
	int			blue;
}				t_sph;

typedef struct s_cyl
{
	char		*id;
	t_vect		*d_coordinates;
	t_vect		*nv_orientation;
	float		diam;
	float		height;
	int			red;
	int			green;
	int			blue;
}				t_cyl;

typedef struct s_matrix
{
	float		mat[4][4];
}				t_matrix;

typedef struct s_vplane
{
	float		width;
	float		height;
	float		x_pixel;
	float		y_pixel;
}				t_vplane;

typedef struct s_scene
{
	t_camera	*camera;
	t_sph		*sphere;
	float		width;
	float		height;
}				t_scene;

//Parser

void		parser(char **argv, t_vars *vars);
float		ft_atof(const char *str);
void		check_file_name(char *file_name);
void		parse_line(char *line, t_vars *vars);
void		parse_ambient(char *line, t_vars *vars);
void		parse_camera(char *line, t_vars *vars);
void		parse_light(char *line, t_vars *vars);
void		parse_plane(char *line, t_vars *vars);
void		parse_sphere(char *line, t_vars *vars);
void		parse_cylinder(char *line, t_vars *vars);
char		**numbers(char *line, int *i);
void		put_numbers(char **num, float *x, float *y, float *z);
void		put_numbers_atoi(char **num, int *x, int *y, int *z);
void		put_numbers_vec(char **num, t_vect *vec);
void		free_array(char **array);

// Figures

void		init(t_vars *vars);
t_amb		*init_amb(void);
t_camera	*new_camera(void);
t_light		*new_light(void);
t_plane		*new_plane(void);
t_sph		*new_sphere(void);
t_cyl		*new_cylinder(void);
t_scene		*new_scene(t_camera *cam, t_sph *sphere);

// UTILS

int			close_win(int keycode);
int			key_hook(int keycode, t_vars *vars);
void		ft_mlx_pixel_put(t_data *img, int x, int y, int color);
int			gradient(int startcolor, int endcolor, int iter, int iter_max);
int			color(int red, int green, int blue);
void		error_exit(int code);
void		free_scene(t_scene *scene);
void		free_camera(t_camera *camera);
void		free_sphere(t_sph *sphere);

//Raytrace

void		raytrace(t_vars *vars, t_scene *scene);
t_vplane	*get_view_plane(float width, float height, float fov);
int			sphere_intersect(t_camera *cam, t_vect *ray, t_sph *sphere);
float cylinder_intersect(t_camera *cam, t_vect *ray, t_cyl *cyl);
float	plane_intersect(t_camera *cam, t_vect *ray, t_plane *plane);

//vector

t_vect		*new_vector(float x, float y, float z);
void		print_vect(t_vect *vec, char *name);
float		dot_product(t_vect *vec1, t_vect *vec2);
void		vect_normalize(t_vect *vec);
float		vect_len(t_vect *vec);
t_vect		*vec_subtraction(t_vect *vec1, t_vect *vec2);
t_vect		*cross_product(t_vect *vec1, t_vect *vec2);
t_vect		*vec_sum(t_vect *vec1, t_vect *vec2);

#endif 
