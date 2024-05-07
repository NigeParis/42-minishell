/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:38:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 14:40:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_listsize(const t_list *lst)
{
	t_list	*it;
	size_t	i;

	i = 0;
	it = (t_list *)lst;
	while (it)
	{
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_listsize_match(const t_list *lst, t_data_is function)
{
	size_t	i;
	t_list	*it;

	i = 0;
	it = (t_list *)lst;
	while (it)
	{
		if (function(it->data))
			i++;
		it = it->next;
	}
	return (i);
}
