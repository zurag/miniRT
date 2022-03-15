/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:26:57 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_line(char *line, t_vars *vars, t_flist **figure)
{
	int	i;

	i = 0;
	if (line[i] == 'A')
		parse_ambient(line, vars);
	else if (line[i] == 'C')
		parse_camera(line, vars);
	else if (line[i] == 'L')
		parse_light(line, vars);
	else if (line[i] == 'p' && line[i + 1] == 'l')
		parse_plane(line, vars, figure);
	else if (line[i] == 's' && line[i + 1] == 'p')
		parse_sphere(line, vars, figure);
	else if (line[i] == 'c' && line[i + 1] == 'y')
		parse_cylinder(line, vars, figure);
}

void	parser(char **argv, t_vars *vars, t_flist **figure)
{
	int		fd;
	char	*line;

	*figure = NULL;
	check_file_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("parser");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line))
	{
		parse_line(line, vars, figure);
		free(line);
	}
	parse_line(line, vars, figure);
	free(line);
}
