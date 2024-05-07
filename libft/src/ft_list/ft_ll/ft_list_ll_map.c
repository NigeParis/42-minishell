/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:04:38 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:04:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_listmap(const t_list *lst, void *(*f)(const void *),
		t_data_apply del)
{
	t_list	*ret;
	t_list	*node;

	ret = NULL;
	if (!f || !del || !lst)
		return (NULL);
	while (lst)
	{
		node = ft_listcreate(f(lst->data));
		if (!node)
			return (ft_listclear(&ret, del), NULL);
		ft_listadd_back(&ret, node);
		lst = lst->next;
	}
	return (ret);
}
