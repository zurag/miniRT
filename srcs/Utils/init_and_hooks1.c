/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_hooks1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_camera	*init_camera(void)
{
	t_camera *camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->id = ft_strdup("C");
	camera->d_origin = new_vector(0.0, 0.0, 0.0);
	camera->nv_direction = new_vector(0.0, 0.0, 0.0);
	camera->fov = 0;
	return (camera);
}

t_light	*init_light(void)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(t_light));
	light->id = ft_strdup("L");
	light->d_point = new_vector(0.0, 0.0, 0.0);
	light->bright = 0.0;
	return (light);
}

t_plane	*init_plane(void)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->id = ft_strdup("pl");
	plane->d_coordinates = new_vector(0.0, 0.0, 0.0);
	plane->nv_orientation = new_vector(0.0, 0.0, 0.0);
	plane->red = 0;
	plane->green = 0;
	plane->blue = 0;
	return (plane);
}

t_sph	*init_sph(void)
{
	t_sph *sph;

	sph = (t_sph *)malloc(sizeof(t_sph));
	sph->id = ft_strdup("sp");
	sph->center = new_vector(0.0, 0.0, 0.0);
	sph->diam = 0.0;
	sph->red = 0;
	sph->green = 0;
	sph->blue = 0;
	return (sph);
}

t_cyl	*init_cyl(void)
{
	t_cyl *cyl;

	cyl = (t_cyl *)malloc(sizeof(t_cyl));
	cyl->id = ft_strdup("cy");
	cyl->d_coordinates = new_vector(0.0, 0.0, 0.0);
	cyl->nv_orientation = new_vector(0.0, 0.0, 0.0);
	cyl->diam = 0.0;
	cyl->height = 0.0;
	cyl->red = 0;
	cyl->green = 0;
	cyl->blue = 0;
	return (cyl);
}
