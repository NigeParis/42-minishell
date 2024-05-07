/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:53 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:02:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_listapply(const t_list *lst, t_data_apply f)
{
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it)
	{
		f(it->data);
		it = it->next;
	}
}

void	ft_listapply_range(const t_list *lst, const t_list *end, t_data_apply f)
{
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it && it != end)
	{
		f(it->data);
		it = it->next;
	}
}

// nxt = lst->next;
// f may modify lst->next, we dont know
void	ft_listapply_range_node(const t_list *lst, const t_list *end,
		t_lnode_apply f)
{
	t_list	*nxt;
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it && it != end)
	{
		nxt = it->next;
		f(it);
		it = nxt;
	}
}
