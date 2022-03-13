///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   scene.c                                            :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2022/03/08 19:26:07 by acollin           #+#    #+#             */
///*   Updated: 2022/03/08 19:26:09 by acollin          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
////#include "minirt.h"
//
//void	free_scene(t_scene *scene)
//{
//	if (scene)
//	{
//		if (scene->camera)
//			free_camera(scene->camera);
//		if (scene->sphere)
//			free_sphere(scene->sphere);
//		free(scene);
//	}
//}
//
//t_scene	*new_scene(t_camera *camera, t_sph *sphere)
//{
//	t_scene	*scene;
//
//	scene = malloc(sizeof(t_scene));
//	if (!scene)
//		error_exit(-1);
//	scene->camera = camera;
//	scene->sphere = sphere;
//	scene->width = WIDTH;
//	scene->height = HEIGHT;
//	return (scene);
//}