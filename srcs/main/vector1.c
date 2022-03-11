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

void	vect_normalize(t_vect *vec)
{
	float	len;

	len = vect_len(vec);
	if (len == 0)
		return ;
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float	dot_product(t_vect *vec1, t_vect *vec2)
{
	float	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}

void	vect_miltipl_on(t_vect *vec, float num)
{
	vec->x *= num;
	vec->y *= num;
	vec->z *= num;
}

t_vect	*cross_product(t_vect *vec1, t_vect *vec2)
{
	float	x;
	float	y;
	float	z;
	t_vect	*res;

	x = (vec1->x * vec2->z) - (vec1->z * vec2->y);
	y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
	res = new_vector(x, y, z);
	return (res);
}
