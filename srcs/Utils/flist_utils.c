/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:27:33 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_flist	*ft_flstnew(void *content, int type)
{
	t_flist	*lst;

	lst = malloc(sizeof(t_flist));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->type = type;
	lst->next = NULL;
	return (lst);
}

int	ft_flstsize(t_flist *flst)
{
	int		i;
	t_flist	*l;

	i = 0;
	l = flst;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_flist	*ft_flstlast(t_flist *flst)
{
	t_flist	*last;

	last = flst;
	if (flst == NULL)
		return (NULL);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_flstadd_front(t_flist **flst, t_flist *new)
{
	if (flst == NULL)
		flst = &new;
	else
	{
		new->next = *flst;
		*flst = new;
	}
}

void	ft_flstadd_back(t_flist **flst, t_flist *new)
{
	t_flist	*final;

	if (!flst && !new)
		return ;
	if (!(*flst))
	{
		*flst = new;
		return ;
	}
	final = *flst;
	while (final->next != NULL)
		final = final->next;
	final->next = new;
}
