/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iron <iron@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:20:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/15 22:24:49 by iron             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_rev(t_dlist **head)
{
	t_dlist	*it;
	t_dlist	*tmp;

	if (!head || !*head)
		return (NULL);
	it = *head;
	while (it)
	{
		tmp = it->next;
		it->next = it->prev;
		it->prev = tmp;
		if (!tmp)
			*head = it;
		it = tmp;
	}
	return (*head);
}
