/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:34:17 by zurag             #+#    #+#             */
/*   Updated: 2022/04/29 20:34:19 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(const char **str, int *sign)
{
	*sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -(*sign);
		(*str)++;
	}
}

static float	ret_atof(int e, float res, int sign)
{
	while (e < 0)
	{
		res *= 0.1;
		e++;
	}
	return (res * sign);
}

float	ft_atof(const char *str)
{
	float	res;
	int		e;
	int		c;
	int		sign;

	e = 0;
	res = 0.0;
	skip_space(&str, &sign);
	c = *str++;
	while (c != '\0' && ft_isdigit(c))
	{
		res = res * 10.0 + (c - '0');
		c = *str++;
	}
	if (c == '.')
	{
		c = *str++;
		while (c != '\0' && ft_isdigit(c))
		{
			res = res * 10.0 + (c - '0');
			e--;
			c = *str++;
		}
	}
	return (ret_atof(e, res, sign));
}
