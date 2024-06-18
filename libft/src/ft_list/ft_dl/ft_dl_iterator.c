/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:27 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 11:34:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_at(const t_dlist *head, size_t index)
{
	size_t	i;
	t_dlist	*it;

	it = (t_dlist *)head;
	i = 0;
	while (i != index)
	{
		i++;
		it = it->next;
	}
	return (it);
}

t_dlist	*ft_dl_end(const t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->next)
		it = it->next;
	return (it);
}

t_dlist	*ft_dl_begin(const t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->prev)
		it = it->prev;
	return (it);
}
