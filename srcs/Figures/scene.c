/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:26:07 by acollin           #+#    #+#             */
/*   Updated: 2022/03/08 19:26:09 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_scene	*new_scene(t_camera *cam, t_sph *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		error_exit(-1);
	scene->cams = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}
