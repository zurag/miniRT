/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_capital.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_ambient(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free(*nums);
			break;
		}
		nums = numbers(line, &i);
		printf("nums[0] = |%s|\n", nums[0]);
		j++;
		if (j == 2)
			put_numbers(nums, &vars->amb->l_rat, NULL, NULL);
		if (j == 3)
			put_numbers_atoi(nums, &vars->amb->red, &vars->amb->green,
				&vars->amb->blue);
		free(*nums);
	}
}

void	parse_camera(char *line, t_vars *vars)
{
	int			i;
	int			j;
	char		**nums;

	i = -1;
	j = 0;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free(*nums);
			break;
		}
		nums = numbers(line, &i);
		j++;
		if (j == 2)
			put_numbers_vec(nums, vars->camera->d_origin);
		else if (j == 3)
			put_numbers_vec(nums, vars->camera->nv_direction);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->camera->fov, NULL, NULL);
		free(nums);
	};
}

void	parse_light(char *line, t_vars *vars)
{
	int		i;
	int		j;
	char	**nums;

	i = -1;
	j = 0;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
		{
			free(*nums);
			break;
		}
		nums = numbers(line, &i);
		j++;
		if (j == 2)
			put_numbers_vec(nums, vars->light->d_point);
		else if (j == 3)
			put_numbers(nums, &vars->light->bright, NULL, NULL);
		free(*nums);
		//BONUS
//		vars->light->red = ft_atoi(nums[0]);
//		vars->light->green = ft_atoi(nums[1]);
//		vars->light->blue = ft_atoi(nums[2]);
	}
}
