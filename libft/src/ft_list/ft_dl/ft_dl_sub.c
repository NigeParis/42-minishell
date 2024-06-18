/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:45 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 11:57:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_subrange(const t_dlist *src, const t_dlist *to)
{
	t_dlist	*ret;
	t_dlist	*prev;
	t_dlist	*new_node;
	t_dlist	*it;

	ret = NULL;
	if (!src)
		return (ret);
	ret = ft_dl_create(src->data);
	if (src == to)
		return (ret);
	prev = ret;
	it = src->next;
	while (it != to)
	{
		new_node = ft_dl_create(it->data);
		if (!new_node)
			return (ft_dl_delete(&prev, NULL), NULL);
		new_node->prev = prev;
		new_node->next = NULL;
		prev->next = new_node;
		prev = new_node;
		it = it->next;
	}
	return (ret);
}
