/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:29:09 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:29:11 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vec_normalize(t_vec *vec)
{
	float	len;

	len = vec_len(vec);
	if (len == 0)
		return ;
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float	dot_product(t_vec *vec1, t_vec *vec2)
{
	float	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}

t_vec	*vec_mult(t_vec *vec, float num)
{
	t_vec	*res;
	float	x;
	float	y;
	float	z;

	res = NULL;
	x = vec->x * num;
	y = vec->y * num;
	z = vec->z * num;
	res = vec_new(x, y, z);
	return (res);
}

t_vec	*cross_product(t_vec *vec1, t_vec *vec2)
{
	float	x;
	float	y;
	float	z;
	t_vec	*res;

	x = (vec1->x * vec2->z) - (vec1->z * vec2->y);
	y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
	res = vec_new(x, y, z);
	return (res);
}
