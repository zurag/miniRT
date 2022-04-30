/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 17:45:29 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_sphere(t_vars *vars, t_sph *sph, float cos, float specular)
{
	int	red;
	int	green;
	int	blue;

	if (cos <= 0)
	{
		cos = 0;
		specular = 0;
	}
	red = sph->red * (vars->amb->l_rat + cos * vars->light->bright
		+ specular);
	green = sph->green * (vars->amb->l_rat + cos * vars->light->bright
		+ specular);
	blue = sph->blue * (vars->amb->l_rat + cos * vars->light->bright
		+ specular);
	return (ft_color(red, green, blue));
}

int	color_plane(t_vars *vars, t_plane *pl, float cos, float specular)
{
	int	red;
	int	green;
	int	blue;

	if (cos < 0)
		cos = 0;
	specular = 0;
	red = pl->red * (vars->amb->l_rat + cos * vars->light->bright);
	green = pl->green * (vars->amb->l_rat + cos * vars->light->bright);
	blue = pl->blue * (vars->amb->l_rat + cos * vars->light->bright);
	return (ft_color(red, green, blue));
}

int	color_cyl(t_vars *vars, t_cyl *cyl, float cos, float specular)
{
	int	red;
	int	green;
	int	blue;

	if (cos < 0)
		cos = 0;
	specular = 0;
	red = cyl->red * (vars->amb->l_rat + cos * vars->light->bright);
	green = cyl->green * (vars->amb->l_rat + cos * vars->light->bright);
	blue = cyl->blue * (vars->amb->l_rat + cos * vars->light->bright);
	return (ft_color(red, green, blue));
}

void	shadow_check(t_inter *shadow, float cos_alpha, float len_light)
{
	if (shadow)
	{
		if (shadow->dist < len_light)
			cos_alpha = 0;
		free(shadow->norm);
		free(shadow->point);
		free(shadow);
	}
}
