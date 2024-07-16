/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 11:38:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"

#include <stdlib.h>

int	t_dl_pop(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*ret;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ret = ft_dl_pop(&list);
	if (list == NULL)
		return (1);
	else if (ret != data1)
		return (2);
	ret = ft_dl_pop(&list);
	if (ret != data2)
		return (3);
	if (list != NULL)
		return (4);
	ret = ft_dl_pop(&list);
	if (ret != NULL)
		return (5);
	ret = ft_dl_pop(NULL);
	if (ret != NULL)
		return (6);
	return (free(data1), free(data2), 0);
}

int	t_dl_pop_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*data3;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	data3 = ft_dl_pop_back(&list);
	if (list == NULL)
		return (1);
	else if (data3 != data2)
		return (1);
	data3 = ft_dl_pop_back(&list);
	if (list != NULL)
		return (1);
	else if (data3 != data1)
		return (1);
	data3 = ft_dl_pop_back(NULL);
	if (data3 != NULL)
		return (1);
	data3 = ft_dl_pop_back(&list);
	if (data3 != NULL)
		return (1);
	free(data1);
	free(data2);
	return (0);
}

int	t_dl_push(void)
{
	t_dlist	*list;
	int		*data1;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	ft_dl_push(&list, data1);
	if (list == NULL)
		return (1);
	else if (list->data != data1)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dl_push_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*data3;

	data1 = malloc(sizeof(int));
	*data1 = 42;
	list = NULL;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_dl_push_back(&list, data1);
	ft_dl_push_back(&list, data2);
	ft_dl_push_back(&list, data3);
	if (ft_dl_size(list) != 3)
		return (1);
	else if (list->data != data1 || list->next->data != data2 || \
	list->next->next->data != data3)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}
