/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:17:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 15:33:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_dl_add_back(t_dlist **head, t_dlist *const added)
{
	t_dlist	*last;

	if (!head || !added)
		return ;
	if (!*head)
		return (ft_dl_add_front(head, added));
	last = ft_dl_end(*head);
	last->next = added;
	added->prev = last;
}

void	ft_dl_add_front(t_dlist **head, t_dlist *const added)
{
	if (!head || !added)
		return ;
	if (!*head)
		return ((void)(*head = added));
	added->next = *head;
	(*head)->prev = added;
	*head = added;
}
