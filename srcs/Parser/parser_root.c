/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/02/07 19:52:24 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_line(char *line, t_vars *vars)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		while (!ft_isalpha(line[i]))
			i++;
		if (line[i] == 'A')
			parse_ambient(line, vars);
		else if (line[i] == 'C')
			parse_camera(line, vars);
		else if (line[i] == 'L')
			parse_light(line, vars);
		else if (line[i] == 'p' && line[i + 1] == 'l')
			parse_plane(line, vars);
		else if (line[i] == 's' && line[i + 1] == 'p')
			parse_sphere(line, vars);
		else if (line[i] == 'c' && line[i + 1] == 'y')
			parse_cylinder(line, vars);
		else if (line[i] == '\0')
			break ;
	}
}

void	parser(char **argv, t_vars *vars)
{
	int		fd;
	int		i;
	char	*line;

	check_file_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("parser");
		exit(EXIT_FAILURE);
	}
	while ((i = get_next_line(fd, &line)))
	{
		printf("line from GNL = |%s|\n", line);
		parse_line(line, vars);
		free(line);
	}
	printf("line from GNL = |%s|\n", line);
	parse_line(line, vars);
	free(line);
}
