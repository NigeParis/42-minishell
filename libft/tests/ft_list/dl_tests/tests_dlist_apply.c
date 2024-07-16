/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:48:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

static void	dnode_add42(t_dlist *node)
{
	*(int *)node->data += 42;
}

int	t_dlapply(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply(list, add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84)
		return (2);
	else if (*(int *)list->next->data != 63)
		return (3);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dlapply_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range(list, list->next, add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || \
	*(int *)list->next->data != 21)
		return (1);
	return (ft_dl_clear(&list, free), 0);
}

int	t_dlapply_range_node(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range_node(list, list->next, dnode_add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || \
	*(int *)list->next->data != 21)
		return (1);
	return (ft_dl_clear(&list, free), 0);
}
