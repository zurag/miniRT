/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_capital.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:26:49 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i] && j < 3)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free_array(nums);
			break ;
		}
		nums = numbers(line, &i);
		j++;
		if (j == 2)
			put_numbers(nums, &vars->amb->l_rat, NULL, NULL);
		if (j == 3)
			put_numbers_atoi(nums, &vars->amb->red, &vars->amb->green,
				&vars->amb->blue);
		free_array(nums);
	}
	vars->amb->color = ft_color(vars->amb->red, vars->amb->green,
							vars->amb->blue);
}

void	parse_camera(char *line, t_vars *vars)
{
	int			i;
	int			j;
	char		**nums;

	i = -1;
	j = 0;
	while (line[++i] && j < 4)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free_array(nums);
			break ;
		}
		nums = numbers(line, &i);
		j++;
		if (j == 2)
			put_numbers_vec(nums, vars->camera->d_origin);
		else if (j == 3)
			put_numbers_vec(nums, vars->camera->nv_direction);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->camera->fov, NULL, NULL);
		free_array(nums);
	}
}

void	parse_light(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i] && j < 3)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free_array(nums);
			break ;
		}
		nums = numbers(line, &i);
		j++;
		if (j == 2)
			put_numbers_vec(nums, vars->light->d_point);
		else if (j == 3)
			put_numbers(nums, &vars->light->bright, NULL, NULL);
		free_array(nums);
	}
}
