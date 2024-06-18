/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll__ll_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iron <iron@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:22:54 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/15 22:24:40 by iron             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_rev(t_list **head)
{
	t_list	*next;
	t_list	*it;
	t_list	*prev;

	if (!head || !*head)
		return (NULL);
	it = *head;
	prev = NULL;
	next = it->next;
	while (next)
	{
		next = it->next;
		it->next = prev;
		prev = it;
		it = next;
	}
	*head = prev;
	return (*head);
}
