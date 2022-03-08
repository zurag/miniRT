/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_intersect(t_camera *cam, t_vect *ray, t_sph *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist1; // ближняя дистанция
	float	dist2; // дальняя точка пересечения
	t_vect	*cam_sphere;


	dist1 = 0;
	dist2 = 0;
	b = 0;
	c = 0;
	cam_sphere = vec_subtraction(cam->d_origin, sphere->center);
	// a = dot_product(ray, ray);
	b = 2 * (dot_product(cam_sphere, ray));
	c = dot_product(cam_sphere, cam_sphere) - (sphere->diam * sphere->diam *
			0.25);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / 2);   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / 2);		// на всякий случай.
	// printf("dist1 == %f dist2 == %f\n", dist1, dist2);
	if (dist1 > 0)
		return (1);
//	t_vect	*hit_position = vect_multipl_on(ray, dist1); // точка
//	соприкосновения
	return (0);
}
