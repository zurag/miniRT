/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flist_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:52:16 by zurag             #+#    #+#             */
/*   Updated: 2022/03/08 19:27:33 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_flst_clear(t_flist *head)
{
	if (head == NULL)
		return ;
	ft_flst_clear(head->next);
	if (head->type == PLANE)
		free_plane(head->content);
	if (head->type == SPHERE)
		free_sphere(head->content);
	if (head->type == CYLINDER)
		free_cylinder(head->content);
	if (head->content)
		free(head->content);
	head->next = NULL;
	if (head)
		free(head);
}
