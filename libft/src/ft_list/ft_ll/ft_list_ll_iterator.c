/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:43:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:03:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_listend(const t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return ((t_list *)lst);
}

t_list	*ft_listat(const t_list *lst, size_t index)
{
	size_t	i;

	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	if (i != index)
		return (NULL);
	return ((t_list *)lst);
}
