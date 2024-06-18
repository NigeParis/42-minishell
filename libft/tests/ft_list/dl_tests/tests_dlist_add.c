/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:48:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:54:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include <stdlib.h>

int	t_dladd_front(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	data2 = malloc(sizeof(int));
	*data = 42;
	*data2 = 21;
	list = ft_dl_create(data2);
	ft_dl_add_front(&list, NULL);
	if (list == NULL || list->next)
		return (1);
	else
	{
		ft_dl_add_front(&list, ft_dl_create(data));
		if (list == NULL || list->data != data || list->next == NULL)
			return (1);
		else if (list->next->data != data2 || list->next->next != NULL)
			return (1);
		else if (list->next->prev != list)
			return (1);
	}
	ft_dl_clear(&list, free);
	ft_dl_add_front(NULL, NULL);
	return (0);
}

int	t_dladd_back(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	list = NULL;
	data = malloc(sizeof(int));
	data2 = malloc(sizeof(int));
	*data = 42;
	*data2 = 21;
	ft_dl_add_back(&list, ft_dl_create(data));
	ft_dl_add_back(&list, NULL);
	if (!list || list->next)
		return (1);
	else
	{
		ft_dl_add_back(&list, ft_dl_create(data2));
		if (!list || list->data != data || !list->next || \
		list->next->data != data2)
			return (1);
		else if (list->next->next != NULL || list->next->prev != list)
			return (1);
	}
	ft_dl_clear(&list, free);
	ft_dl_add_front(NULL, NULL);
	return (0);
}
