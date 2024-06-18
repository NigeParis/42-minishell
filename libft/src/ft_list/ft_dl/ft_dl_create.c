/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:05 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 11:45:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_create(const void *data)
{
	t_dlist	*ret;

	ret = ft_dl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)data;
	return (ret);
}

t_dlist	*ft_dl_copy_node(const t_dlist *const other)
{
	t_dlist	*ret;

	ret = ft_dl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)other->data;
	ret->next = (t_dlist *)other->next;
	ret->prev = (t_dlist *)other->prev;
	return (ret);
}

t_dlist	*ft_dl_copy_list(const t_dlist *const other)
{
	t_dlist	*node;
	t_dlist	*head;
	t_dlist	*prev;
	t_dlist	*it;

	it = (t_dlist *)other;
	node = NULL;
	head = NULL;
	prev = NULL;
	while (it)
	{
		node = ft_dl_copy_node(it);
		if (!node)
			return (ft_dl_delete(&head, NULL), head);
		node->prev = prev;
		if (prev)
			prev->next = node;
		else
			head = node;
		if (it->next)
			prev = node;
		it = it->next;
	}
	return (head);
}
