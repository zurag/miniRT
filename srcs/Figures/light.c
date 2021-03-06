/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:25:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_light(t_light *light)
{
	if (light)
	{
		if (light->id)
			free(light->id);
		if (light->d_point)
			free(light->d_point);
		free(light);
	}
}

t_light	*new_light(void)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		error_exit(-1);
	light->id = ft_strdup("L");
	light->d_point = vec_new(0.0, 0.0, 0.0);
	light->bright = 0.0;
	return (light);
}
