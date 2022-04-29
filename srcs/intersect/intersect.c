/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:16:58 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:35:00 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_inter	*ret_intersect(t_flist *figure_lst,
			float dist, t_vec *ray_origin, t_vec *ray_dir)
{
	t_inter	*ret;
	t_ray	*ray;

	ray = init_ray(ray_dir, ray_origin);
	ret = malloc(sizeof(t_inter));
	ret->point = get_point(ray_origin, dist, ray_dir);
	ret->dist = dist;
	ret->figure = figure_lst->content;
	ret->type = figure_lst->type;
	if (figure_lst->type == PLANE)
	{
		ret->norm = vec_new(((t_plane *)figure_lst->content)->nv_orientation->x,
				((t_plane *)figure_lst->content)->nv_orientation->y,
				((t_plane *)figure_lst->content)->nv_orientation->z);
	}
	else if (figure_lst->type == SPHERE)
	{
		ret->norm = sph_normal(ret->point, figure_lst->content);
	}
	else if (figure_lst->type == CYLINDER)
		ret->norm = cyl_normal(ret->point, figure_lst->content, dist, ray);
	free(ray);
	return (ret);
}

float	figure_dist(t_vec *ray, t_vec *ray_origin, t_flist *figure_lst)
{
	if (figure_lst->type == PLANE)
		return (plane_intersect(ray_origin, ray, figure_lst->content));
	else if (figure_lst->type == SPHERE)
		return (sphere_intersect(ray_origin, ray, figure_lst->content));
	else if (figure_lst->type == CYLINDER)
		return (cylinder_intersect(ray_origin, ray, figure_lst->content));
	else
		return (-1);
}

t_inter	*intersect(t_vec *ray, t_flist *figure_lst, t_vec *ray_origin)
{
	t_inter	*ret_inter;
	t_flist	*start;
	float	*dist;
	int		min_nbr;
	int		i;

	i = 0;
	start = figure_lst;
	dist = ft_calloc(ft_flstsize(start), sizeof(float));
	while (figure_lst)
	{
		dist[i++] = figure_dist(ray, ray_origin, figure_lst);
		figure_lst = figure_lst->next;
	}
	min_nbr = find_min_nbr(dist, ft_flstsize(start));
	if (dist[min_nbr] < 0 || min_nbr == -1)
	{
		free(dist);
		return (NULL);
	}
	ret_inter = ret_intersect(find_node_lst(start, min_nbr), dist[min_nbr],
			ray_origin, ray);
	free(dist);
	return (ret_inter);
}
