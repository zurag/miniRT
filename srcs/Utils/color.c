/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/15 23:08:29 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_sphere_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst)
{
	t_sph	*tmp_sph;
	float	cos_alpha;
	t_vec	*light;
	int		color_from_light;
	t_inter	*shadow;

	tmp_sph = (t_sph *)ret_inter->figure;
	light = vec_subtraction(vars->light->d_point, ret_inter->point);
	cos_alpha = (dot_product(ret_inter->norm, light)) / (vec_len(light));
	vec_normalize(light);
	shadow = intersect(light, figure_lst, ret_inter->point);
	free(light);
//	if (shadow)
//		printf("check\n");
	if (shadow || cos_alpha < 0)
		cos_alpha = 0;
	color_from_light = ft_color(
			tmp_sph->red * (vars->amb->l_rat + cos_alpha),
			tmp_sph->green * (vars->amb->l_rat + cos_alpha),
			tmp_sph->blue * (vars->amb->l_rat + cos_alpha));
	return (color_from_light);
}

int	get_plane_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst)
{
	t_plane	*tmp_plane;
	float	cos_alpha;
	t_vec	*light;
	int		color_from_light;
	t_inter	*shadow;

	tmp_plane = (t_plane *)ret_inter->figure;
	light = vec_subtraction(ret_inter->point, vars->light->d_point);
	cos_alpha = (dot_product(ret_inter->norm, light)) / (vec_len(light));
//	printf("cos_alpha = %f\n", cos_alpha);
//	print_vect(ret_inter->norm, "plane norm");
	vec_normalize(light);
	vec_mult(light, -1);
	shadow = intersect(light, figure_lst, ret_inter->point);
	free(light);
	// if (shadow)
	// 	printf("check\n");
	if (shadow || cos_alpha < 0)
		cos_alpha = 0;
//	printf("red == %d, green  == %d, blue == %d\n", tmp_plane->red, tmp_plane->green, tmp_plane->blue);
	color_from_light = ft_color(
			tmp_plane->red * (vars->amb->l_rat + cos_alpha),
			tmp_plane->green * (vars->amb->l_rat + cos_alpha),
			tmp_plane->blue * (vars->amb->l_rat + cos_alpha));
	return (color_from_light);
}

int	get_cylinder_color(t_vars *vars, t_inter *ret_inter, t_flist *figure_lst)
{
	t_cyl	*tmp_cyl;
	float	cos_alpha;
	t_vec	*light;
	int		color_from_light;
	t_inter	*shadow;

	tmp_cyl = (t_cyl *)ret_inter->figure;
	light = vec_subtraction(vars->light->d_point, ret_inter->point);
	cos_alpha = (dot_product(ret_inter->norm, light)) / (vec_len(light));
	vec_normalize(light);
	shadow = intersect(light, figure_lst, ret_inter->point);
	free(light);
	if (shadow || cos_alpha < 0)
		cos_alpha = 0;
	color_from_light = ft_color(
			tmp_cyl->red * (vars->amb->l_rat + cos_alpha),
			tmp_cyl->green * (vars->amb->l_rat + cos_alpha),
			tmp_cyl->blue * (vars->amb->l_rat + cos_alpha));
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

int	gradient(int startcolor, int endcolor, int iter, int iter_max)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = ((endcolor >> 16) - (startcolor >> 16)) / (iter + 1);
	increment[1] = ((endcolor >> 8) & 0xFF - (startcolor >> 8) & 0xFF)
		/ (iter + 1);
	increment[2] = ((endcolor & 0xFF) - (startcolor & 0xFF)) / (iter + 1);
	new[0] = ((startcolor) >> 16) + fabs(iter_max * increment[0]);
	new[1] = (((startcolor) >> 8) & 0xFF) + fabs(iter_max * increment[1]);
	new[2] = ((startcolor) & 0xFF) + fabs(iter_max * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}
