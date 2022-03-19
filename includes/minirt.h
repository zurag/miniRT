/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:20 by zurag             #+#    #+#             */
/*   Updated: 2022/03/17 22:48:34 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vector.h"
# include "sphere.h"
# include "camera.h"
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

// Type of figure
# define PLANE 1
# define SPHERE 2
# define CYLINDER 3

// Window and keyboard
# define WIDTH 800
# define HEIGHT 600
# define ESC_KEY 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define EPSILON 0.000001
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
typedef struct s_flist	t_flist;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

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
	t_flist		*figure;
}				t_vars;
//PARSING

typedef struct s_amb
{
	char		*id;
	float		l_rat;
	int			color;
	int			red;
	int			green;
	int			blue;
}				t_amb;

typedef struct s_camera
{
	char		*id;
	t_vec		*d_origin;
	t_vec		*nv_direction;
	int			fov;
}				t_camera;

typedef struct s_light
{
	char		*id;
	t_vec		*d_point;
	float		bright;
}				t_light;

typedef struct s_plane
{
	char		*id;
	t_vec		*d_coordinates;
	t_vec		*nv_orientation;
	int			color;
	int			red;
	int			green;
	int			blue;
}				t_plane;

typedef struct s_sph
{
	char		*id;
	t_vec		*center;
	float		diam;
	float		rad;
	int			color;
	int			red;
	int			green;
	int			blue;
}				t_sph;

typedef struct s_cyl
{
	char		*id;
	t_vec		*d_coordinates;
	t_vec		*nv_orientation;
	float		diam;
	float		height;
	int			color;
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

typedef struct s_flist
{
	void		*content;
	int			type;
	t_flist		*next;
}				t_flist;

typedef struct s_intersect
{
	t_vec		*norm;
	t_vec		*point;
	float		dist;
	int			type;
	void		*figure;
}				t_inter;

//Parser

void		parser(char **argv, t_vars *vars, t_flist **figure);
float		ft_atof(const char *str);
void		check_file_name(char *file_name);
void		parse_line(char *line, t_vars *vars, t_flist **figure);
void		parse_ambient(char *line, t_vars *vars);
void		parse_camera(char *line, t_vars *vars);
void		parse_light(char *line, t_vars *vars);
void		parse_plane(char *line, t_vars *vars, t_flist **figure);
void		parse_sphere(char *line, t_vars *vars, t_flist **figure);
void		parse_cylinder(char *line, t_vars *vars, t_flist **figure);
char		**numbers(char *line, int *i);
void		put_numbers(char **num, float *x, float *y, float *z);
void		put_numbers_atoi(char **num, int *x, int *y, int *z);
void		put_numbers_vec(char **num, t_vec *vec);
void		free_array(char **array);

// Figures

void		init(t_vars *vars);
t_amb		*new_amb(void);
t_camera	*new_camera(void);
t_light		*new_light(void);
t_plane		*new_plane(void);
t_sph		*new_sphere(void);
t_cyl		*new_cylinder(void);
void		free_amb(t_amb *ambient);
void		free_camera(t_camera *camera);
void		free_light(t_light *light);
void		free_plane(t_plane *plane);
void		free_sphere(t_sph *sphere);
void		free_cylinder(t_cyl *cyl);

// UTILS

int			close_win(int keycode);
int			key_hook(int keycode, t_vars *vars);
void		ft_mlx_pixel_put(t_data *img, int x, int y, int color);
int			gradient(int startcolor, int endcolor, int iter, int iter_max);
int			ft_color(int red, int green, int blue);
void		error_exit(int code);

//Raytrace

void		raytrace(t_vars *vars, t_flist **figure);
t_vplane	*get_view_plane(float width, float height, float fov);
int			ft_pixel_color(t_vars *vars, t_vec *ray, t_flist **figure);
float		get_dist(t_vars *vars, t_vec *ray, t_flist **figure);
int			get_color(t_vars *vars, t_inter *ret_inter, t_flist *figure);
int			get_sphere_color(t_vars *vars, t_inter *ret_inter,
				t_flist *figure_lst);
int			get_plane_color(t_vars *vars, t_inter *ret_inter,
				t_flist *figure_lst);
int			get_cylinder_color(t_vars *vars, t_inter *ret_inter,
				t_flist *figure_lst);
float		plane_intersect(t_vec *ray_origin, t_vec *ray, t_plane *plane);
float		sphere_intersect(t_vec *ray_origin, t_vec *ray, t_sph *sphere);
float		cylinder_intersect(t_vec *ray_origin, t_vec *ray, t_cyl *cyl);
t_vec		*get_point(t_vec *ray_origin, float dist, t_vec *ray_dir);

t_vec		*cyl_normal(t_vec *point, t_cyl *cyl, float dist, t_vec *ray, t_vec *ray_origin);

t_vec		*sph_normal(t_vec *point, t_sph *sph);
int			find_min_nbr(float	*arr, int size);
t_flist		*find_node_lst(t_flist *figure_lst, int nbr);
t_inter		*intersect(t_vec *ray, t_flist *figure_lst,
				t_vec *ray_origin);

// FIGURES LIST
t_flist		*ft_flstnew(void *content, int type);
void		ft_flstadd_front(t_flist **flst, t_flist *new);
void		ft_flstadd_back(t_flist **flst, t_flist *new);
int			ft_flstsize(t_flist *flst);
t_flist		*ft_flstlast(t_flist *flst);

//vector

t_vec		*vec_new(float x, float y, float z);
void		vec_print(t_vec *vec, char *name);
float		dot_product(t_vec *vec1, t_vec *vec2);
t_vec		*cross_product(t_vec *vec1, t_vec *vec2);
void		vec_normalize(t_vec *vec);
float		vec_len(t_vec *vec);
t_vec		*vec_sum(t_vec *vec1, t_vec *vec2);
t_vec		*vec_subtraction(t_vec *vec1, t_vec *vec2);
void		vec_mult(t_vec *vec, float num);
void		print_vect(t_vec *vec, char *name);

#endif 
