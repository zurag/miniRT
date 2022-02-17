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
	camera->view_x = 0.0;
	camera->view_y = 0.0;
	camera->view_z = 0.0;
	camera->vec_x = 0.0;
	camera->vec_y = 0.0;
	camera->vec_z = 0.0;
	camera->fov = 0;
	return (camera);
}

t_light	*init_light(void)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(t_light));
	light->id = ft_strdup("L");
	light->point_x = 0.0;
	light->point_y = 0.0;
	light->point_z = 0.0;
	light->bright = 0.0;
	return (light);
}

t_plane	*init_plane(void)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->id = ft_strdup("pl");
	plane->x = 0.0;
	plane->y = 0.0;
	plane->z = 0.0;
	plane->vec_x = 0.0;
	plane->vec_y = 0.0;
	plane->vec_z = 0.0;
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
	sph->center_x = 0.0;
	sph->center_y = 0.0;
	sph->center_z = 0.0;
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
	cyl->x = 0.0;
	cyl->y = 0.0;
	cyl->z = 0.0;
	cyl->vec_x = 0.0;
	cyl->vec_y = 0.0;
	cyl->vec_z = 0.0;
	cyl->diam = 0.0;
	cyl->height = 0.0;
	cyl->red = 0;
	cyl->green = 0;
	cyl->blue = 0;
	return (cyl);
}
