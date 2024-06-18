/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:01:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:20:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_dl_delete_self(void)
{
	int		*data;
	int		*data2;
	int		*data3;
	t_dlist	*list;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_dl_add_back(&list, ft_dl_create(data3));
	ft_dl_delete_self(list->next, NULL);
	if (!list || list->data != data || !list->next || \
	list->next->data != data3 || list->next->next != NULL)
		return (1);
	ft_dl_clear(&list, free);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	*data2 = 21;
	list = ft_dl_create(data3);
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_delete_self(list->next, free);
	if (list->next != NULL || list->data != data3)
		return (1);
	return (ft_dl_clear(&list, free), \
	ft_dl_delete_self(NULL, NULL), 0);
}
/*
	ft_dl_add_back(&list, ft_dl_create(data3));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list2 = list->next;                                          
		// 42 <-(21)<=>(63)-> NULL
	nb_deleted = ft_dl_delete_range(list, list->next, NULL);
		// NULL <-(21)<=>(63)-> NULL
	ft_dl_add_front(&list2, ft_dl_create(data));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list = list2;
	nb_deleted = ft_dl_delete_range(list->next, list->next->next, free);
		// NULL <-(42)<=>(63)-> NULL
*/

int	t_dldelete_range(void)
{
	t_dlist	*list;
	t_dlist	*list2;
	int		*data_array[3];
	int		nb_deleted;

	create_2elem_dlist(&list, (void **)&data_array[0], (void **)&data_array[1]);
	data_array[2] = malloc(sizeof(int));
	*data_array[2] = 63;
	ft_dl_add_back(&list, ft_dl_create(data_array[2]));
	list2 = list->next;
	nb_deleted = ft_dl_delete_range(list, list->next, NULL);
	if (nb_deleted != 1 || ft_dl_size(list2) != 2 || *(int *)list2->data \
	!= *data_array[1] || *(int *)list2->next->data != *data_array[2])
		return (1);
	ft_dl_add_front(&list2, ft_dl_create(data_array[0]));
	list = list2;
	nb_deleted = ft_dl_delete_range(list->next, list->next->next, free);
	if (nb_deleted != 1 || ft_dl_size(list) != 2 || *(int *)list2->data \
	!= *data_array[0] || *(int *)list2->next->data != *data_array[2])
		return (1);
	return (ft_dl_clear(&list2, free), 0);
}

int	t_dldelete(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	int		*data3;
	int		nb_deleted;

	data3 = malloc(sizeof(int));
	*data3 = 63;
	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_add_back(&list, ft_dl_create(data3));
	nb_deleted = ft_dl_delete(&list, NULL);
	if (nb_deleted != 3)
		return (1);
	else if (list != NULL)
		return (1);
	ft_dl_add_front(&list, ft_dl_create(data));
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_add_back(&list, ft_dl_create(data3));
	nb_deleted = ft_dl_delete(&list, free);
	if (nb_deleted != 3)
		return (1);
	else if (list != NULL)
		return (1);
	return (0);
}
