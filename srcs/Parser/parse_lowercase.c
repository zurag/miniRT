/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/09 20:36:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(char *line, t_vars *vars, t_list **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_plane	*plane;
	t_list	*new_node;
	(void)vars;

	i = -1;
	j = 0;
	plane = new_plane();
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
			put_numbers_vec(nums, plane->d_coordinates);
		else if (j == 3)
			put_numbers_vec(nums, plane->nv_orientation);
		else if (j == 4)
			put_numbers_atoi(nums, &plane->red, &plane->red, &plane->red);
		free_array(nums);
	}
	plane->color = ft_color(plane->red, plane->green, plane->blue);
	new_node = ft_lstnew(plane);
	ft_lstadd_back(figure, new_node);
}

void	parse_sphere(char *line, t_vars *vars, t_list **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_sph	*sph;
	t_list	*new_node;
	(void)vars;

	i = -1;
	j = 0;
	sph = new_sphere();
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
			put_numbers_vec(nums, sph->center);
		else if (j == 3)
			put_numbers(nums, &sph->diam, NULL, NULL);
		else if (j == 4)
			put_numbers_atoi(nums, &sph->red, &sph->green, &sph->blue);
		free_array(nums);
	}
	sph->rad = sph->diam * 0.5;
	sph->color = ft_color(sph->red, sph->green, sph->blue);
	new_node = ft_lstnew(sph);
	ft_lstadd_back(figure, new_node);
}

void	parse_cylinder(char *line, t_vars *vars, t_list **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_cyl	*cyl;
	t_list	*new_node;
	(void)vars;

	i = -1;
	j = 0;
	cyl = new_cylinder();
	while (line[++i] && j < 6)
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
			put_numbers_vec(nums, cyl->d_coordinates);
		else if (j == 3)
			put_numbers_vec(nums, cyl->nv_orientation);
		else if (j == 4)
			put_numbers(nums, &cyl->diam, NULL, NULL);
		else if (j == 5)
			put_numbers(nums, &cyl->height, NULL, NULL);
		else if (j == 6)
			put_numbers_atoi(nums, &cyl->red, &cyl->green, &cyl->blue);
		free_array(nums);
	}
	cyl->color = ft_color(cyl->red, cyl->green, cyl->blue);
	new_node = ft_lstnew(cyl);
	ft_lstadd_back(figure, new_node);
}
