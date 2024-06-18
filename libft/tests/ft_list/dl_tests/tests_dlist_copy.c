/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:59:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_dlcopy_node(void)
{
	int		*data;
	t_dlist	*list;
	t_dlist	*copy;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	copy = ft_dl_copy_node(list);
	if (copy == NULL)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next != list->next)
		return (1);
	else if (copy->prev != list->prev)
		return (1);
	ft_dl_clear(&list, free);
	ft_dl_clear(&copy, NULL);
	return (0);
}

int	t_dlcopy_list(void)
{
	t_dlist	*list;
	t_dlist	*copy;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	copy = ft_dl_copy_list(list);
	if (copy == NULL)
		return (1);
	else if (copy->data != list->data)
		return (1);
	else if (copy->next == NULL)
		return (1);
	else if (copy->next->data != list->next->data)
		return (1);
	else if (copy->next->next != NULL)
		return (1);
	else if (copy->next->prev != copy)
		return (1);
	ft_dl_clear(&list, free);
	ft_dl_clear(&copy, NULL);
	return (0);
}
