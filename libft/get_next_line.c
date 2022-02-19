/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:43:13 by acollin           #+#    #+#             */
/*   Updated: 2021/10/06 20:43:27 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flag_err(int flag, char **line)
{
	if (flag < 0)
	{
		free(*line);
		*line = NULL;
		return (flag);
	}
	else if (flag == 0)
		return (flag);
	else
		return (1);
}

static void	line_new(char **line, char **buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
}

static	char	*remainder(char **line, char **rem)
{
	char	*prem;
	char	*temp;

	prem = NULL;
	if (*rem != NULL)
	{
		prem = ft_strchr(*rem, '\n');
		if (prem)
		{
			*prem = '\0';
			*line = ft_strdup(*rem);
			temp = *rem;
			*rem = ft_strdup(++prem);
			free(temp);
		}
		else
		{
			*line = *rem;
			*rem = NULL;
		}
	}
	else
		*line = (char *) ft_calloc(sizeof(char), 1);
	return (prem);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*rem[2048];
	char			*pbuf;
	int				flag;

	flag = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	pbuf = remainder(line, &rem[fd]);
	while (flag > 0 && !pbuf)
	{
		buf = (char *) ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		flag = read(fd, buf, BUFFER_SIZE);
		pbuf = ft_strchr(buf, '\n');
		if (pbuf)
		{
			*pbuf = '\0';
			pbuf++;
			rem[fd] = ft_strdup(pbuf);
		}
		line_new(line, &buf);
		free(buf);
	}
	return (flag_err(flag, line));
}
