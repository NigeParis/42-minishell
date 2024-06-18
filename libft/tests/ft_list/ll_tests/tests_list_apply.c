/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:18:39 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:47:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/ll_tests.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

static void	lnode_add42(t_list *node)
{
	*(int *)node->data += 42;
}

int	t_ll_apply(void)
{
	const int	data3 = 63;
	const int	data4 = 84;
	t_list		*list;
	int			*data;
	int			*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_ll_apply(list, add42);
	if (!list || !list->next || list->next->next != NULL
		|| *(int *)list->data != data4 || *(int *)list->next->data != data3)
		return (1);
	ft_ll_apply(list, NULL);
	if (!list || !list->next || list->next->next != NULL
		|| *(int *)list->data != data4 || *(int *)list->next->data != data3)
		return (1);
	ft_ll_clear(&list, free);
	return (0);
}

int	t_ll_apply_range(void)
{
	t_list		*list;
	int			*data;
	int			*data2;
	const int	data3 = 84;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_ll_apply_range(list, list->next, add42);
	if (*(int *)list->data != data3)
		return (1);
	else if (ft_ll_size(list) != 2)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	ft_ll_apply_range(list, list->next, NULL);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (*(int *)list->data != data3)
		return (1);
	else if (*(int *)list->next->data != 21)
		return (1);
	ft_ll_apply_range(NULL, NULL, add42);
	ft_ll_clear(&list, free);
	return (0);
}

int	t_ll_apply_range_node(void)
{
	const int	data3 = 84;
	t_list		*list;
	int			*data;
	int			*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_ll_apply_range_node(list, list->next, lnode_add42);
	if (*(int *)list->data != data3 || !list->next
		|| *(int *)list->next->data != 21 || list->next->next != NULL)
		return (1);
	ft_ll_apply_range_node(list, list->next, NULL);
	if (*(int *)list->data != data3 || !list->next
		|| *(int *)list->next->data != 21 || list->next->next != NULL)
		return (1);
	ft_ll_apply_range_node(NULL, NULL, lnode_add42);
	ft_ll_clear(&list, free);
	return (0);
}
