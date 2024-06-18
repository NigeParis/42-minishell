/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:04:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 14:09:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_map(const t_list *lst, t_data_tr f, t_data_apply del)
{
	t_list	*ret;
	t_list	*node;

	ret = NULL;
	if (!f || !del || !lst)
		return (NULL);
	while (lst)
	{
		node = ft_ll_create(f(lst->data));
		if (!node)
			return (ft_ll_clear(&ret, del), NULL);
		ft_ll_add_back(&ret, node);
		lst = lst->next;
	}
	return (ret);
}
