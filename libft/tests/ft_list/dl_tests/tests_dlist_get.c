/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:04:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:04:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_dlget_datas(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	void	**datas;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	datas = ft_dl_get_datas(list);
	if (datas == NULL)
		return (1);
	else if (datas[0] != data)
		return (1);
	else if (datas[1] != data2)
		return (1);
	if (ft_dl_get_datas(NULL) != NULL)
		return (1);
	ft_dl_clear(&list, free);
	free(datas);
	return (0);
}

int	t_dlget_nodes(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	t_dlist	**nodes;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	nodes = ft_dl_get_nodes(list);
	if (nodes == NULL)
		return (1);
	else if (nodes[0] != list)
		return (1);
	else if (nodes[1] != list->next)
		return (1);
	if (ft_dl_get_nodes(NULL) != NULL)
		return (1);
	ft_dl_clear(&list, free);
	free(nodes);
	return (0);
}
