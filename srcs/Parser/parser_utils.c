/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/09 20:36:35 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**numbers(char *line, int *i)
{
	char	*tmp;
	char	**tmp_arr;
	int		j;

	j = *i;
//	printf("line[%d] = |%c|\n", j, line[j]);
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
//	printf("line[%d] = |%c|\n", j, line[j]);
	tmp = ft_substr(line, j, *i - j);
	printf("tmp = |%s|\n", tmp);
	tmp_arr = ft_split(tmp, ',');
	free(tmp);
	return (tmp_arr);
}

void	put_numbers(char **num, float *x, float *y, float *z)
{
	if (x)
		*x = ft_atof(num[0]);
	if (y)
		*y = ft_atof(num[1]);
	if (z)
		*z = ft_atof(num[2]);
}

void	put_numbers_atoi(char **num, int *x, int *y, int *z)
{
	if (x)
		*x = ft_atoi(num[0]);
	if (y)
		*y = ft_atoi(num[1]);
	if (z)
		*z = ft_atoi(num[2]);
}

void	check_file_name(char *file_name)
{
	int		i;
	int		j;
	char	*ext;

	i = -1;
	j = 0;
	while (file_name[++i])
	{
		if (file_name[i] == '.')
		{
			j = i;
			while (file_name[i])
				i++;
			ext = ft_substr(file_name, j + 1, i - j);
			break ;
		}
	}
	if (ft_strcmp(ext, "rt") != 0)
	{
		printf("Wrong file extension\n");
		exit(EXIT_FAILURE);
	}
}

double	ft_atof(const char *str)
{
	double	res;
	int		e;
	int		c;
	int		sign;

	e = 0;
	res = 0.0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ((c = *str++) != '\0' && ft_isdigit(c))
		res = res * 10.0 + (c - '0');
	if (c == '.') {
		while ((c = *str++) != '\0' && ft_isdigit(c))
		{
			res = res * 10.0 + (c - '0');
			e--;
		}
	}
	while (e < 0)
	{
		res *= 0.1;
		e++;
	}
	return (res * sign);
}
