/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 14:21:37 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mult_vec_matrix(t_vec *src, t_vec *dst, t_matrix *m)
{
	float	w;

	dst->x = src->x * m->mat[0][0] + src->y * m->mat[1][0]
		+ src->z * m->mat[2][0] + m->mat[3][0];
	dst->y = src->x * m->mat[0][1] + src->y * m->mat[1][1]
		+ src->z * m->mat[2][1] + m->mat[3][1];
	dst->z = src->x * m->mat[0][2] + src->y * m->mat[1][2]
		+ src->z * m->mat[2][2] + m->mat[3][2];
	w = src->x * m->mat[1][3] + src->y * m->mat[1][3]
		+ src->x * m->mat[2][3] + m->mat[3][3];
	if (w != 1 && w != 0)
	{
		dst->x /= w;
		dst->y /= w;
		dst->z /= w;
	}
}

void	mult_dir_matrix(t_vec *src, t_vec *dst, t_matrix *m)
{
	float	a;
	float	b;
	float	c;

	a = src->x * 1 + src->y * m->mat[1][0] + src->z * m->mat[2][0];
	b = src->x * m->mat[0][1] + src->y * 1 + src->z * m->mat[2][1];
	c = src->x * m->mat[0][2] + src->y * m->mat[1][2] + src->z * 1;
	dst->x = a;
	dst->y = b;
	dst->z = c;
}

t_matrix	*look_at(t_vec *from, t_vec *to)
{
	t_vec		*forward;
	t_vec		*right;
	t_vec		*up;
	t_vec		*tmp;
	t_matrix	*cam_to_world;

	tmp = vec_new(0, 1, 0);
	forward = vec_subtraction(from, to);
	vec_normalize(forward);
	right = cross_product(tmp, forward);
	up = cross_product(forward, right);
	cam_to_world = new_matrix(right, up, forward, from);
	free(forward);
	free(right);
	free(up);
	return (cam_to_world);
}

t_matrix	*new_matrix(t_vec *right, t_vec *up, t_vec *forward, t_vec *from)
{
	t_matrix	*mat;

	mat = (t_matrix *)malloc(sizeof(t_matrix));
	if (NULL == mat)
		return (NULL);
	mat->mat[0][0] = right->x;
	mat->mat[0][1] = right->y;
	mat->mat[0][2] = right->z;
	mat->mat[1][0] = up->x;
	mat->mat[1][1] = up->y;
	mat->mat[1][2] = up->z;
	mat->mat[2][0] = forward->x;
	mat->mat[2][1] = forward->y;
	mat->mat[2][2] = forward->z;
	mat->mat[3][0] = from->x;
	mat->mat[3][1] = from->y;
	mat->mat[3][2] = from->z;
	return (mat);
}
