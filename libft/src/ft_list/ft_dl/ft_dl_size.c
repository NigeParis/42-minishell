/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:50 by iron              #+#    #+#             */
/*   Updated: 2023/12/11 09:51:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_dl_size(const t_dlist *head)
{
	t_dlist	*it;	
	size_t	i;

	i = 0;
	it = (t_dlist *)head;
	while (it)
	{
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_dl_size_of_data(const t_dlist *head, t_data_is function)
{
	t_dlist	*it;
	size_t	i;

	it = (t_dlist *)head;
	i = 0;
	while (it)
	{
		if (function(it->data))
			i++;
		it = it->next;
	}
	return (i);
}
