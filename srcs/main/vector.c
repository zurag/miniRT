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

t_vect	*new_vector(float x, float y, float z)
{
	t_vect	*vec;

	vec = malloc(sizeof(t_vect));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vect	*vec_subtraction(t_vect *vec1, t_vect *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (new_vector(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return (new_vector(vec1->x * -1, vec1->y * -1, vec1->z * -1));
	return (new_vector(vec1->x - vec2->x,
			vec1->y - vec2->y, vec1->z - vec2->z));
}

t_vect	*vec_sum(t_vect *vec1, t_vect *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return (new_vector(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return (new_vector(vec1->x, vec1->y, vec1->z));
	return (new_vector(vec1->x + vec2->x,
			vec1->y + vec2->y, vec1->z + vec2->z));
}

float	vect_len(t_vect *vec)
{
	float	len;

	if (!vec)
		return (0);
	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}
