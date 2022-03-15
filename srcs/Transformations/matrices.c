/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:28:04 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mult_vec_matrix(t_vec *src, t_vec *dst)
{
	float	w;

	dst->x = src->x * m[0][0] + src->y * m[1][0] + src->z * m[2][0] + m[3][0];
	dst->y = src->x * m[0][1] + src->y * m[1][1] + src->z * m[2][1] + m[3][1];
	dst->z = src->x * m[0][2] + src->y * m[1][2] + src->z * m[2][2] + m[3][2];
	w = src->x * m[1][3] + src->y * m[1][3] + src->x * m[2][3] + m[3][3];
	if (w != 1 && w != 0)
	{
		dst->x /= w;
		dst->y /= w;
		dst->z /= w;
	}
}

t_matrix	*cam_to_world()