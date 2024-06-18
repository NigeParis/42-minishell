/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:12:59 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:05:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_ll_find(const t_list *list, const void *data,
		int (*cmp)(const void *, const void *))
{
	t_list	*it;

	it = (t_list *)list;
	while (it)
	{
		if (data == it->data || (cmp && cmp(it->data, data) == 0))
			return (it->data);
		it = it->next;
	}
	return (NULL);
}
