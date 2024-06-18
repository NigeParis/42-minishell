/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:40:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 11:19:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_create(const void *const data)
{
	t_list	*ret;

	ret = ft_ll_new();
	if (!ret)
		return (ret);
	ret->data = (void *)data;
	return (ret);
}

t_list	*ft_ll_copy_node(const t_list *const other)
{
	t_list	*ret;

	ret = ft_ll_new();
	if (!ret)
		return (ret);
	ret->data = (void *)other->data;
	ret->next = (t_list *)other->next;
	return (ret);
}

t_list	*ft_ll_copy_list(const t_list *const other)
{
	t_list	*node;
	t_list	*head;
	t_list	*prev;
	t_list	*it;

	it = (t_list *)other;
	head = ft_ll_copy_node(it);
	if (!head)
		return (head);
	prev = head;
	it = (t_list *)it->next;
	while (it)
	{
		node = ft_ll_copy_node(it);
		if (!node)
			return (ft_ll_clear(&head, NULL), NULL);
		prev->next = node;
		prev = node;
		it = (t_list *)it->next;
	}
	return (head);
}
