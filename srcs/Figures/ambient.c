/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:26:17 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:26:19 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_amb(t_amb *ambient)
{
	if (ambient)
	{
		if (ambient->id)
			free(ambient->id);
		free(ambient);
	}
}

t_amb	*new_amb(void)
{
	t_amb	*amb;

	amb = (t_amb *)malloc(sizeof(t_amb));
	amb->id = ft_strdup("A");
	amb->l_rat = 0.0;
	amb->red = 0;
	amb->green = 0;
	amb->blue = 0;
	amb->color = 0;
	return (amb);
}
