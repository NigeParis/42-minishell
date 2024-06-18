/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:32:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:33:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_ll_get_datas(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	**datas;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	datas = ft_ll_get_datas(list);
	if (!datas || datas[2] != NULL || datas[0] != data || \
		datas[1] != data2)
		return (1);
	if (ft_ll_get_datas(NULL) != NULL)
		return (1);
	ft_ll_clear(&list, free);
	free(datas);
	return (0);
}

int	t_ll_get_nodes(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	**nodes;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	nodes = ft_ll_get_nodes(list);
	if (!nodes || nodes[2] != NULL || nodes[0] != list || \
		nodes[1] != list->next)
		return (1);
	if (ft_ll_get_nodes(NULL) != NULL)
		return (1);
	ft_ll_clear(&list, free);
	free(nodes);
	return (0);
}
