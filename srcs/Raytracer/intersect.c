/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/08 19:27:52 by acollin          ###   ########.fr       */
=======
/*   Updated: 2022/03/09 20:45:45 by zurag            ###   ########.fr       */
>>>>>>> miniRT/zurag
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

<<<<<<< HEAD
int	sphere_intersect(t_camera *cam, t_vect *ray, t_sph *sphere)
{
//	float	a;
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
//	 a = dot_product(ray, ray);
	b = 2 * (dot_product(cam_sphere, ray));
//	printf("b = %f\n", b);
	c = dot_product(cam_sphere, cam_sphere)
		- (sphere->rad * sphere->rad);
//	printf("c = %f\n", c);
	discr = (b * b) - (4 * c);
//	printf("discr = %f\n", discr);
	free(cam_sphere);
	if (discr < 0)
		return (0);                           // No intersection
	dist1 = (((b * -1) - sqrt(discr)) / 2);   // видимая область
	dist2 = (((b * -1) + sqrt(discr)) / 2);		// на всякий случай.
//	 printf("dist1 == %f dist2 == %f\n", dist1, dist2);
//	printf("dist1 = %f\n", dist2);
	if (dist1 > 0)
		return (1);
//	t_vect	*hit_position = vect_multipl_on(ray, dist1); // точка
//	соприкосновения
	return (0);
}
=======
// int	intersect(t_camera *camera, t_vector *ray, t_vars *vars)
// {
	
// 	return (1);
// }

>>>>>>> miniRT/zurag
