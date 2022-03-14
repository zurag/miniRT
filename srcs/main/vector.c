/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:29:02 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:29:04 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*vec_new(float x, float y, float z)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*vec_subtraction(t_vec *vec1, t_vec *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (vec_new(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return (vec_new(vec1->x * -1, vec1->y * -1, vec1->z * -1));
	return (vec_new(vec1->x - vec2->x,
			vec1->y - vec2->y, vec1->z - vec2->z));
}

t_vec	*vec_sum(t_vec *vec1, t_vec *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (vec_new(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return (vec_new(vec1->x, vec1->y, vec1->z));
	return (vec_new(vec1->x + vec2->x,
			vec1->y + vec2->y, vec1->z + vec2->z));
}

float	vec_len(t_vec *vec)
{
	float	len;

	if (!vec)
		return (0);
	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}
