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

void	parse_ambient(char *line, t_vars *vars, t_list **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_amb	*amb;
	t_list	*new_node;
	(void)vars;

	i = -1;
	j = 0;
	amb = new_amb();
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
			put_numbers(nums, &amb->l_rat, NULL, NULL);
		if (j == 3)
			put_numbers_atoi(nums, &amb->red, &amb->green, &amb->blue);
		free_array(nums);
	}
	amb->color = ft_color(amb->red, amb->green, amb->blue);
	new_node = ft_lstnew(amb);
	ft_lstadd_front(figure, new_node);
}

void	parse_camera(char *line, t_vars *vars, t_list **figure)
{
	int			i;
	int			j;
	char		**nums;
	t_camera	*camera;
	t_list		*new_node;
	(void)vars;

	i = -1;
	j = 0;
	camera = new_camera();
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
			put_numbers_vec(nums, camera->d_origin);
		else if (j == 3)
			put_numbers_vec(nums, camera->nv_direction);
		else if (j == 4)
			put_numbers_atoi(nums, &camera->fov, NULL, NULL);
		free_array(nums);
	}
	new_node = ft_lstnew(camera);
	ft_lstadd_front(figure, new_node);
}

void	parse_light(char *line, t_vars *vars, t_list **figure)
{
	int		i;
	int		j;
	char	**nums;
	t_light	*light;
	t_list	*new_node;
	(void)vars;

	i = -1;
	j = 0;
	light = new_light();
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
			put_numbers_vec(nums, light->d_point);
		else if (j == 3)
			put_numbers(nums, &light->bright, NULL, NULL);
		free_array(nums);
	}
	new_node = ft_lstnew(light);
	ft_lstadd_front(figure, new_node);
}
