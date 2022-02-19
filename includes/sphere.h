#ifndef SPHERE_H
# define SPHERE_H


typedef struct s_sphere{
	t_vect		*center;
	float		radius;
}				t_sphere;

t_sphere	*new_sphere(t_vect *center, float radius);


#endif