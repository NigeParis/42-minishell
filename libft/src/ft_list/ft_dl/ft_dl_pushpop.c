/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_pushpop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:38 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 11:38:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

t_dlist	*ft_dl_push(t_dlist **node, const void *data)
{
	t_dlist	*added;

	added = ft_dl_create(data);
	added->next = *node;
	if (*node)
		(*node)->prev = added;
	*node = added;
	return (added);
}

t_dlist	*ft_dl_push_back(t_dlist **node, const void *data)
{
	t_dlist	*added;
	t_dlist	*it;

	it = *node;
	if (!*node)
		return (ft_dl_push(node, data));
	added = ft_dl_create(data);
	while (it->next)
		it = it->next;
	it->next = added;
	added->prev = it;
	return (*node);
}

void	*ft_dl_pop(t_dlist **node)
{
	void	*data;
	t_dlist	*it;

	data = NULL;
	if (!node || !*node)
		return (NULL);
	it = *node;
	*node = (*node)->next;
	data = it->data;
	free(it);
	if (*node)
		(*node)->prev = NULL;
	return (data);
}

void	*ft_dl_pop_back(t_dlist **node)
{
	void	*data;
	t_dlist	*it;
	t_dlist	*prev;

	data = NULL;
	prev = NULL;
	if (!node || !*node)
		return (NULL);
	it = ft_dl_end(*node);
	data = it->data;
	prev = it->prev;
	if (prev)
		prev->next = NULL;
	else
		*node = NULL;
	free(it);
	return (data);
}
