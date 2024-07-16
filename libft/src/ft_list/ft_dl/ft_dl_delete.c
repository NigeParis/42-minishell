/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:10 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 11:56:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

int	ft_dl_delete_self(t_dlist *node, t_data_apply del)
{
	if (!node)
		return (FTLIST_FAILURE);
	if (del)
		del(node->data);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
	return (FTLIST_SUCCESS);
}

size_t	ft_dl_delete_range(t_dlist *start, const t_dlist *target,
		t_data_apply del)
{
	t_dlist	*next;
	t_dlist	*prev;
	size_t	i;

	i = 0;
	next = NULL;
	prev = NULL;
	if (start && start->prev)
		prev = start->prev;
	while (start != target)
	{
		next = start->next;
		if (del)
			del(start->data);
		free(start);
		start = next;
		i++;
	}
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return (i);
}

size_t	ft_dl_delete(t_dlist **head, t_data_apply del)
{
	size_t	i;
	t_dlist	*firs_elem;

	if (!head)
		return (0);
	firs_elem = ft_dl_begin(*head);
	i = ft_dl_delete_range(firs_elem, NULL, del);
	*head = NULL;
	return (i);
}

/*
size_t	ft_dl_delete_dup(t_dlist **src)
{
	t_dlist	**node_ptrs;
	size_t	nb_del;
	size_t	length;

	node_ptrs = NULL;
	nb_del = 0;
	length = 0;
	if (!*src)
		return (0);
	node_ptrs = ft_dl_get_nodes(*src);
	if (!node_ptrs)
		return (0);
	length = ft_dl_count(*src);
	for (size_t j = 0; j + 1 != length; j++) {
		for (size_t k = j + 1; k != length; k++) {
			if (!node_ptrs[j] || !node_ptrs[k])
				continue ;
			if (node_ptrs[j]->data == node_ptrs[k]->data) {
				ft_dl_delete_self(node_ptrs[k]);
				node_ptrs[k] = NULL;
				nb_del++;
				j++;
			}
		}
	}
	free(node_ptrs);
	return (nb_del);
}
*/
