#ifndef INTERSECT_H
# define INTERSECT_H

float	sphere_intersect(t_camera *cam, t_vect *ray, t_sphere *sphere);
float cylinder_intersect(t_camera *cam, t_vect *ray, t_cyl *cyl);
float	plane_intersect(t_camera *cam, t_vect *ray, t_plane *plane);

#endif