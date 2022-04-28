/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/28 15:48:33 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_sphere_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst,
						t_vec *ray_dir)
{
	t_sph	*tmp_sph;
	float	cos_alpha;
	float	specular;
	t_vec	*light;
	int		color_from_light;
	t_inter	*shadow;
	float	len_light;

	tmp_sph = (t_sph *)ret_inter->figure;
	shadow = NULL;
	cos_alpha = 0;
	specular = 0;
	if (vars->light)
	{
		light = vec_subtraction(vars->light->d_point, ret_inter->point);
		len_light = vec_len(light);
		vec_normalize(light);
		cos_alpha = dot_product(ret_inter->norm, light);
		shadow = intersect(light, figure_lst, ret_inter->point);
		specular = specular_light(ret_inter->norm, light, ray_dir);
		free(light);
	}
	// else
	// 	printf("NO LIGHT\n");

	if (cos_alpha < 0)
	{
		specular = 0;
		cos_alpha = 0;
	}
	if (shadow)
	{
		// printf("IN SHADOW PLANE\n");
		if (shadow->dist < len_light)
		{
			cos_alpha = 0;
		}
	}
	else
		printf("sphere cos == %f\n", cos_alpha);
	// if (shadow || cos_alpha < 0)
	// {
	// 	cos_alpha = 0;
	// 	specular = 0;
	// }
	color_from_light = ft_color(
			tmp_sph->red * (vars->amb->l_rat + cos_alpha * vars->light->bright
				+ specular),
			tmp_sph->green * (vars->amb->l_rat + cos_alpha * vars->light->bright
				+ specular),
			tmp_sph->blue * (vars->amb->l_rat + cos_alpha * vars->light->bright
				+ specular));
	return (color_from_light);
}

int	get_plane_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst,
					t_vec *ray_dir)
{
	t_plane	*tmp_plane;
	float	cos_alpha;
	t_vec	*light;
	float	len_light;
	int		color_from_light;
	t_inter	*shadow;
	// float	specular;

	len_light = 0;
	// specular = 0;
	tmp_plane = (t_plane *)ret_inter->figure;
	shadow = NULL;
	cos_alpha = 0;
	(void)ray_dir;
	if (vars->light)
	{
		light = vec_subtraction(ret_inter->point, vars->light->d_point);
		len_light = vec_len(light);
		vec_normalize(light);
		cos_alpha = dot_product(ret_inter->norm, light);
		vec_mult(light, -1);
		shadow = intersect(light, figure_lst, ret_inter->point);
		// specular = specular_light(ret_inter->norm, light, ray_dir);
		free(light);
	}
	if (cos_alpha < 0)
	{
		// specular = 0;
		cos_alpha = 0;
	}
	if (shadow)
	{
		// printf("IN SHADOW PLANE\n");
		if (shadow->dist < len_light)
		{
			// specular = 0;
			cos_alpha = 0;
		}
	}
	color_from_light = ft_color(
			tmp_plane->red * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright),
			tmp_plane->green * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright),
			tmp_plane->blue * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright));




	// 	color_from_light = ft_color(
	// tmp_plane->red * (vars->amb->l_rat
	// 	+ cos_alpha * vars->light->bright + specular),
	// tmp_plane->green * (vars->amb->l_rat
	// 	+ cos_alpha * vars->light->bright + specular),
	// tmp_plane->blue * (vars->amb->l_rat
	// 	+ cos_alpha * vars->light->bright + specular));
	return (color_from_light);
}

int	get_cylinder_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst,
						t_vec *ray_dir)
{
	t_cyl	*tmp_cyl;
	float	cos_alpha;
	t_vec	*light;
	int		color_from_light;
	float	len_light;
	t_inter	*shadow;
	float	specular;

	specular = 0;
	tmp_cyl = (t_cyl *)ret_inter->figure;
	shadow = NULL;
	cos_alpha = 0;
	(void)ray_dir;
	cyl_flag = 0;

	if (vars->light)
	{
		light = vec_subtraction(vars->light->d_point, ret_inter->point);
		len_light = vec_len(light);
		// print_vect(light, "light");
		// printf("len light == %f\n", len_light);
		print_vect(ret_inter->norm, "ret_inter->norm");
		// print_vect(ret_inter->norm, "ret inter");
		vec_normalize(light);
		cos_alpha = (dot_product(ret_inter->norm, light));
		// cos_alpha = (dot_product(ret_inter->norm, light) / len_light);
//		printf("%f\n", cos_alpha);
		// vec_mult(light, -1);
		shadow = intersect(light, figure_lst, ret_inter->point);
		// specular = specular_light(ret_inter->norm, light, ray_dir);
		free(light);
	}
	if (cos_alpha < 0)
	{
		specular = 0;
		cos_alpha = 0;
	}
	cyl_flag = 0;
	if (shadow)
	{
		// printf("SHADOW\n");
		// cos_alpha = 0;
		if (shadow->dist < len_light) //&& shadow->dist > 0.02
		{
			specular = 0;
			cos_alpha = 0;
		}
		// if (!(shadow->figure == ret_inter->figure))
		// {
		// }
	}
	else
		printf("cos == %f\n", cos_alpha);
	color_from_light = ft_color(
			tmp_cyl->red * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright),
			tmp_cyl->green * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright),
			tmp_cyl->blue * (vars->amb->l_rat
				+ cos_alpha * vars->light->bright));




	
	// color_from_light = ft_color(
	// 		tmp_cyl->red * (vars->amb->l_rat
	// 			+ cos_alpha * vars->light->bright + specular),
	// 		tmp_cyl->green * (vars->amb->l_rat
	// 			+ cos_alpha * vars->light->bright + specular),
	// 		tmp_cyl->blue * (vars->amb->l_rat
	// 			+ cos_alpha * vars->light->bright + specular));
	return (color_from_light);
	
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
	t_vec	*r;

	vec_mult(l, -1);
	nl = 2 * dot_product(n, l);
	vec_mult(n, nl);
	r = vec_subtraction(n, l);
	specular = pow(dot_product(v, r), 200);
	return (specular);
}
