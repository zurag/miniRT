#include "minirt.h"


// void	print_vect(t_vect *vec, char *name)
// {
// 	printf("%s : x== %f, y == %f, z == %f\n", name, vec->x, vec->y, vec->z);
// }

int	find_min_nbr(float	*arr, int size)
{
	int		i;
	int		min;

	i = 0;
	min = -1;
	while (i < size)
	{
		if (arr[i] < arr[min] && arr[i] != -1)
			min = i;
		i++;
	}
	return (min);
}


t_flist	*find_node_lst(t_flist *figure_lst, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr && figure_lst)
	{
		i++;
		figure_lst = figure_lst->next;
	}
	if (i != nbr)
		return (NULL);
	return (figure_lst);
}


t_vec	*get_point(t_vec *ray_origin, float dist, t_vec *ray_dir)
{
	t_vec *point;

	vec_mult(ray_dir, dist);
	point = vec_sum(ray_origin, ray_dir);
	return (point);
}