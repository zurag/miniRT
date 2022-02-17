/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:20 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:48:00 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

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

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int 		x;
	int 		y;
	t_data		*img;
	t_amb		*amb;
	t_camera	*camera;
	t_light		*light;
	t_plane		*plane;
	t_sph		*sph;
	t_cyl		*cyl;
}				t_vars;
//PARSING

typedef struct	s_amb {
	char 		*id;
	double 		light_ratio;
	int 		red;
	int 		green;
	int			blue;
}				t_amb;

typedef struct	s_camera {
	char 		*id;
	double 		view_x;
	double 		view_y;
	double 		view_z;
	double 		vec_x;
	double 		vec_y;
	double 		vec_z;
	int 		fov;
}				t_camera;

typedef struct	s_light {
	char 		*id;
	double 		point_x;
	double 		point_y;
	double 		point_z;
	double 		bright;

}				t_light;

typedef struct	s_plane {
	char 		*id;
	double 		x;
	double 		y;
	double 		z;
	double 		vec_x;
	double 		vec_y;
	double 		vec_z;
	int 		red;
	int 		green;
	int 		blue;
}				t_plane;

typedef struct	s_sph {
	char 		*id;
	double 		center_x;
	double 		center_y;
	double 		center_z;
	double 		diam;
	int 		red;
	int 		green;
	int 		blue;
}				t_sph;

typedef struct	s_cyl {
	char 		*id;
	double 		x;
	double 		y;
	double 		z;
	double 		vec_x;
	double 		vec_y;
	double 		vec_z;
	double 		diam;
	double 		height;
	int 		red;
	int 		green;
	int 		blue;
}				t_cyl;

//Parser

void	parser(char **argv, t_vars *vars);
double	ft_atof(const char *str);
void	check_file_name(char *file_name);
void	parse_line(char *line, t_vars *vars);
void	parse_ambient(char *line, t_vars *vars);
void	parse_camera(char *line, t_vars *vars);
void	parse_light(char *line, t_vars *vars);
void	parse_plane(char *line, t_vars *vars);
void	parse_sphere(char *line, t_vars *vars);
void	parse_cylinder(char *line, t_vars *vars);
char	**numbers(char *line, int *i);
void	put_numbers(char **num, double *x, double *y, double *z);
void	put_numbers_atoi(char **num, int *x, int *y, int *z);


void		init(t_vars *vars);
t_amb 		*init_amb(void);
t_camera	*init_camera(void);
t_light		*init_light(void);
t_plane		*init_plane(void);
t_sph		*init_sph(void);
t_cyl		*init_cyl(void);

int		close_win(int keycode);
int		key_hook(int keycode, t_vars *vars);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		gradient(int startcolor, int endcolor, int iter, int iter_max);

#endif 
