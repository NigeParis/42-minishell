/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll__ll_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:10:57 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:06:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_subrange(const t_list *lst, const t_list *end)
{
	t_list	*sub;

	sub = NULL;
	if (!lst)
		return (sub);
	if (lst == end)
		return (ft_ll_create(lst->data));
	while (lst && lst != end)
	{
		ft_ll_push_back(&sub, lst->data);
		lst = lst->next;
	}
	return (sub);
}
