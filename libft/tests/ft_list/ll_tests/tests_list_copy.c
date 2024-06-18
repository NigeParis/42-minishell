/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listcopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:24:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:25:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/ll_tests.h"
#include <stdlib.h>

int	t_ll_copy_node(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_ll_create(data);
	copy = ft_ll_copy_node(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next != list->next)
		return (1);
	free(data);
	free(list);
	free(copy);
	return (0);
}

int	t_ll_copy_list(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;
	int		*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	copy = ft_ll_copy_list(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (!copy->next)
		return (1);
	else if (copy->next->data != list->next->data)
		return (1);
	else if (copy->next->next != NULL)
		return (1);
	ft_ll_clear(&list, free);
	ft_ll_clear(&copy, NULL);
	return (0);
}
