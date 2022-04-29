/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 20:06:03 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_figure_numbr(int j, char **nums, void *figure, int type)
{
	t_sph	*sph;
	t_plane	*plane;

	if (type == SPHERE)
	{
		sph = (t_sph *)figure;
		if (j == 2)
			put_numbers_vec(nums, sph->center);
		else if (j == 3)
			put_numbers(nums, &sph->diam, NULL, NULL);
		else if (j == 4)
			put_numbers_atoi(nums, &sph->red, &sph->green, &sph->blue);
	}
	else if (type == PLANE)
	{
		plane = (t_plane *)figure;
		if (j == 2)
			put_numbers_vec(nums, plane->d_coordinates);
		else if (j == 3)
			put_numbers_vec(nums, plane->nv_orientation);
		else if (j == 4)
			put_numbers_atoi(nums, &plane->red, &plane->green, &plane->blue);
	}
}

static void	put_cyl_numbr(int j, char **nums, t_cyl *cyl)
{
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
}

void	parse_plane(char *line, t_flist **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_plane	*plane;
	t_flist	*new_node;

	i = -1;
	j = 0;
	plane = new_plane();
	while (line[++i] && j < 4)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			break ;
		nums = numbers(line, &i);
		j++;
		put_figure_numbr(j, nums, plane, PLANE);
		free_array(nums);
	}
	plane->color = ft_color(plane->red, plane->green, plane->blue);
	new_node = ft_flstnew(plane, PLANE);
	ft_flstadd_back(figure, new_node);
}

void	parse_sphere(char *line, t_flist **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_sph	*sph;
	t_flist	*new_node;

	i = -1;
	j = 0;
	sph = new_sphere();
	while (line[++i] && j < 4)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			break ;
		nums = numbers(line, &i);
		j++;
		put_figure_numbr(j, nums, sph, SPHERE);
		free_array(nums);
	}
	sph->rad = sph->diam * 0.5;
	sph->color = ft_color(sph->red, sph->green, sph->blue);
	new_node = ft_flstnew(sph, SPHERE);
	ft_flstadd_back(figure, new_node);
}

void	parse_cylinder(char *line, t_flist **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_cyl	*cyl;
	t_flist	*new_node;

	i = -1;
	j = 0;
	cyl = new_cylinder();
	while (line[++i] && j < 6)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			break ;
		nums = numbers(line, &i);
		j++;
		put_cyl_numbr(j, nums, cyl);
		free_array(nums);
	}
	cyl->color = ft_color(cyl->red, cyl->green, cyl->blue);
	new_node = ft_flstnew(cyl, CYLINDER);
	ft_flstadd_back(figure, new_node);
}
