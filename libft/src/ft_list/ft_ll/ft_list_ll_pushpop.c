/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_pushpop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:02:47 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:06:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	*ft_listpush(t_list **lst, const void *data)
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_listcreate(data);
	if (!new)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (*lst);
}

t_list	*ft_listpush_back(t_list **lst, const void *data)
{
	t_list	*added;

	if (!lst)
		return (NULL);
	added = ft_listcreate(data);
	if (!added)
		return (NULL);
	if (!*lst)
		*lst = added;
	else
		ft_listend(*lst)->next = added;
	return (*lst);
}

void	*ft_listpop(t_list **lst)
{
	t_list	*tmp;
	void	*data;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	data = (*lst)->data;
	*lst = (*lst)->next;
	ft_free((void **)&tmp);
	return (data);
}

void	*ft_listpop_back(t_list **lst)
{
	t_list	*pre_last;
	void	*data;

	if (!lst || !*lst)
		return (NULL);
	if (!(*lst)->next)
		return (ft_listpop(lst));
	pre_last = *lst;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	data = pre_last->next->data;
	free(pre_last->next);
	pre_last->next = NULL;
	return (data);
}
