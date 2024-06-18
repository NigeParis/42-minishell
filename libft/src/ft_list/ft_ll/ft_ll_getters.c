/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_getters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:54:40 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/14 17:23:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

void	**ft_ll_get_datas(const t_list *src)
{
	void	**datas;
	size_t	i;

	if (!src)
		return (NULL);
	datas = ft_calloc(sizeof(void *), ft_ll_size(src) + 1);
	if (!datas)
		return (NULL);
	i = 0;
	while (src)
	{
		datas[i] = src->data;
		src = src->next;
		i++;
	}
	return (datas);
}

t_list	**ft_ll_get_nodes(const t_list *src)
{
	t_list	**nodes;
	size_t	i;

	if (!src)
		return (NULL);
	nodes = ft_calloc(sizeof(t_list *), ft_ll_size(src) + 1);
	if (!nodes)
		return (NULL);
	i = 0;
	while (src)
	{
		nodes[i] = (t_list *)src;
		src = src->next;
		i++;
	}
	return (nodes);
}
