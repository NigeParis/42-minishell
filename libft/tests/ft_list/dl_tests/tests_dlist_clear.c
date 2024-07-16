/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:56:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:57:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"

#include <stdlib.h>

int	t_dlclear(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	ft_dl_clear(&list, NULL);
	list = ft_dl_create(data);
	ft_dl_clear(&list, free);
	return (0);
}

//
//ft_dl_add_back(&list, ft_dl_create(data3))
//	data -> data2 -> data3
//ft_dl_clear_range(list->next, list->next->next, NULL)
//	data -> NULL -> data3
//ft_dl_add_back(&list, ft_dl_create(data2))
//	data -> NULL -> data3 -> data2
//ft_dl_clear_range(list->next->next, NULL, free)
//	data -> NULL -> NULL -> NULL
//ft_dl_delete_range(list, NULL, NULL)
//	delete nodes
//

int	t_dlclear_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	int		*data3;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_dl_add_back(&list, ft_dl_create(data3));
	ft_dl_clear_range(list->next, list->next->next, NULL);
	if ((ft_dl_size(list) != 3) || (list->data != data || \
	list->next->data != NULL || list->next->next->data != data3))
		return (1);
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_clear_range(list->next->next, NULL, free);
	if (ft_dl_size(list) != 4 || list->data != data \
	|| list->next->data != NULL || list->next->next->data != NULL)
		return (2);
	ft_dl_clear_range(list, NULL, free);
	ft_dl_clear_range(NULL, NULL, free);
	ft_dl_delete_range(list, NULL, NULL);
	return (0);
}
