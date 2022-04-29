/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:46:27 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 13:46:28 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	find_min_nbr(float	*arr, int size)
{
	int		i;
	int		min;

	i = 0;
	min = -1;
	while (i < size)
	{
		if (arr[i] > 0)
		{
			if (min == -1 || arr[i] < arr[min])
				min = i;
		}
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
	return (figure_lst);
}

t_vec	*get_point(t_vec *ray_origin, float dist, t_vec *ray_dir)
{
	t_vec	*point;
	t_vec	*new_raydir;

	new_raydir = new_vec_mult(ray_dir, dist);
	point = vec_sum(ray_origin, new_raydir);
	free(new_raydir);
	return (point);
}
