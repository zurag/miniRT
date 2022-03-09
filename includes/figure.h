#ifndef FIGURE_H
# define FIGURE_H


typedef struct s_sphere{
	t_vect		*center;
	float		radius;
}				t_sphere;

typedef struct	s_plane{
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


t_sphere	*new_sphere(t_vect *center, float radius);


#endif