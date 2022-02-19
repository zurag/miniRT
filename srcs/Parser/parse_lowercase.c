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
			put_numbers(nums, &vars->plane->x, &vars->plane->y,
				&vars->plane->z);
		else if (j == 3)
			put_numbers(nums, &vars->plane->vec_x, &vars->plane->vec_y,
				&vars->plane->vec_z);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->plane->red, &vars->plane->red,
				&vars->plane->red);
		free(*nums);
//		vars->plane->x = ft_atof(nums[0]);
//		vars->plane->y = ft_atof(nums[1]);
//		vars->plane->z = ft_atof(nums[2]);
//
//		vars->plane->vec_x = ft_atof(nums[0]);
//		vars->plane->vec_y = ft_atof(nums[1]);
//		vars->plane->vec_z = ft_atof(nums[2]);
//
//		vars->plane->red = ft_atoi(nums[0]);
//		vars->plane->green = ft_atoi(nums[1]);
//		vars->plane->blue = ft_atoi(nums[2]);
	}
}

void	parse_sphere(char *line, t_vars *vars)
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
			put_numbers(nums, &vars->sph->center_x, &vars->sph->center_y,
				&vars->sph->center_z);
		else if (j == 3)
			put_numbers(nums, &vars->sph->diam, NULL, NULL);
		else if (j == 4)
			put_numbers_atoi(nums, &vars->sph->red, &vars->sph->green,
				&vars->sph->blue);
		free(*nums);

//		vars->sph->center_x = ft_atof(nums[0]);
//		vars->sph->center_y = ft_atof(nums[1]);
//		vars->sph->center_z = ft_atof(nums[2]);
//
//		vars->sph->diam = ft_atof(nums[0]);
//
//		vars->sph->red = ft_atoi(nums[0]);
//		vars->sph->green = ft_atoi(nums[1]);
//		vars->sph->blue = ft_atoi(nums[2]);
	}
}

void	parse_cylinder(char *line, t_vars *vars)
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
			put_numbers(nums, &vars->cyl->x, &vars->cyl->y,	&vars->cyl->z);
		else if (j == 3)
			put_numbers(nums, &vars->cyl->vec_x, &vars->cyl->vec_y,
				&vars->cyl->vec_z);
		else if (j == 4)
			put_numbers(nums, &vars->cyl->diam, NULL, NULL);
		else if (j == 5)
			put_numbers(nums, &vars->cyl->height, NULL, NULL);
		else if (j == 6)
			put_numbers_atoi(nums, &vars->cyl->red, &vars->cyl->green,
				&vars->cyl->blue);
		free(*nums);

//		vars->cyl->x = ft_atof(nums[0]);
//		vars->cyl->y = ft_atof(nums[1]);
//		vars->cyl->z = ft_atof(nums[2]);
//
//		vars->cyl->vec_x = ft_atof(nums[0]);
//		vars->cyl->vec_y = ft_atof(nums[1]);
//		vars->cyl->vec_z = ft_atof(nums[2]);
//
//		vars->cyl->diam = ft_atof(nums[0]);
//
//		vars->cyl->height = ft_atof(nums[0]);
//
//		vars->cyl->red = ft_atoi(nums[0]);
//		vars->cyl->green = ft_atoi(nums[1]);
//		vars->cyl->blue = ft_atoi(nums[2]);
	}
}
