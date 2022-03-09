/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_plane(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

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
			put_numbers_vec(nums, vars->plane->d_coordinates);
		else if (j == 3)
			put_numbers_vec(nums, vars->plane->nv_orientation);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->plane->red, &vars->plane->red,
				&vars->plane->red);
		free_array(nums);
	}
}

void	parse_sphere(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i] && j < 4)
	{
		printf("line in parse sph[%d] = |%c|\n", i, line[i]);
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
			put_numbers_vec(nums, vars->sph->center);
		else if (j == 3)
			put_numbers(nums, &vars->sph->diam, NULL, NULL);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->sph->red, &vars->sph->green,
				&vars->sph->blue);
		free_array(nums);
	}
}

void	parse_cylinder(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i] && j < 6)
	{
		printf("line in parse cyl[%d] = |%c|\n", i, line[i]);
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
			put_numbers_vec(nums, vars->cyl->d_coordinates);
		else if (j == 3)
			put_numbers_vec(nums, vars->cyl->nv_orientation);
		else if (j == 4)
			put_numbers(nums, &vars->cyl->diam, NULL, NULL);
		else if (j == 5)
			put_numbers(nums, &vars->cyl->height, NULL, NULL);
		else if (j == 6)
			put_numbers_atoi(nums, &vars->cyl->red, &vars->cyl->green,
				&vars->cyl->blue);
		free_array(nums);
	}
}
