/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:45:29 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_sphere_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst,
						t_vec *ray_dir)
{
	float	cos_alpha;
	float	spec;
	t_vec	*light;
	t_inter	*shadow;
	float	len_light;

	shadow = NULL;
	cos_alpha = 0;
	len_light = 0;
	spec = 0;
	if (vars->light)
	{
		light = vec_subtraction(vars->light->d_point, ret_inter->point);
		len_light = vec_len(light);
		vec_normalize(light);
		cos_alpha = dot_product(ret_inter->norm, light);
		shadow = intersect(light, figure_lst, ret_inter->point);
		spec = specular_light(ret_inter->norm, light, ray_dir);
		free(light);
	}
	shadow_check(shadow, cos_alpha, len_light);
	return (color_sphere(vars, (t_sph *)ret_inter->figure, cos_alpha, spec));
}

int	get_plane_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst)
{
	t_plane	*tmp_plane;
	float	cos_alpha;
	t_vec	*light;
	float	len_light;
	t_inter	*shadow;

	len_light = 0;
	tmp_plane = (t_plane *)ret_inter->figure;
	shadow = NULL;
	cos_alpha = 0;
	if (vars->light)
	{
		light = vec_subtraction(ret_inter->point, vars->light->d_point);
		len_light = vec_len(light);
		vec_normalize(light);
		cos_alpha = dot_product(ret_inter->norm, light);
		vec_mult_on(light, -1);
		shadow = intersect(light, figure_lst, ret_inter->point);
		free(light);
	}
	shadow_check(shadow, cos_alpha, len_light);
	return (color_plane(vars, tmp_plane, cos_alpha, 0));
}

int	get_cylinder_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst)
{
	t_cyl	*tmp_cyl;
	float	cos_alpha;
	t_vec	*light;
	float	len_light;
	t_inter	*shadow;

	tmp_cyl = (t_cyl *)ret_inter->figure;
	shadow = NULL;
	len_light = 0;
	cos_alpha = 0;
	if (vars->light)
	{
		light = vec_subtraction(vars->light->d_point, ret_inter->point);
		len_light = vec_len(light);
		vec_normalize(light);
		cos_alpha = (dot_product(ret_inter->norm, light));
		shadow = intersect(light, figure_lst, ret_inter->point);
		free(light);
	}
	shadow_check(shadow, cos_alpha, len_light);
	return (color_cyl(vars, tmp_cyl, cos_alpha, 0));
}

int	ft_color(int red, int green, int blue)
{
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return (red << 16 | green << 8 | blue);
}

float	specular_light(t_vec *n, t_vec *l, t_vec *v)
{
	float	specular;
	float	nl;
	t_vec	*new_l;
	t_vec	*new_n;
	t_vec	*r;

	new_l = new_vec_mult(l, -1);
	nl = 2 * dot_product(n, new_l);
	new_n = new_vec_mult(n, nl);
	r = vec_subtraction(new_n, new_l);
	specular = pow(dot_product(v, r), 200);
	free(new_l);
	free(new_n);
	free(r);
	return (specular);
}
