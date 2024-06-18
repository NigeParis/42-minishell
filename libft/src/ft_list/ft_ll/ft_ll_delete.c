/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:09:13 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 15:09:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_ll_delone(t_list *lst, t_data_apply del)
{
	if (!lst)
		return ;
	if (del)
		del(lst->data);
	free(lst);
}

size_t	ft_ll_delete_range(t_list *lst, const t_list *end, t_data_apply del)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	if (!lst || !del)
		return (i);
	while (lst && lst != end)
	{
		i++;
		tmp = lst->next;
		del(lst->data);
		free(lst);
		lst = tmp;
	}
	return (i);
}
