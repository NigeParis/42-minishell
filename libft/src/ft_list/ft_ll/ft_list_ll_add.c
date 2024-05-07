/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:48:35 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:40:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_listadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_listadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_listlast(*lst)->next = new;
}
