/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:46:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include <stdlib.h>

/*
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2)); // (21)-> NULL
	ft_ll_add_front(&list, ft_ll_create(data)); // (42)-> (21)-> NULL
	---
	ft_ll_add_front(NULL, list); // null resiliency
	ft_ll_clear(&list, free);
*/

int	t_ll_add_front(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2));
	ft_ll_add_front(&list, ft_ll_create(data));
	if (!list || list->data != data || !list->next
		|| list->next->data != data2 || list->next->next != NULL)
		return (1);
	ft_ll_add_front(NULL, list);
	ft_ll_clear(&list, free);
	return (0);
}

int	t_ll_add_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_ll_create(data);
	ft_ll_add_back(&list, ft_ll_create(data2));
	if (!list || list->data != data || !list->next)
		return (1);
	else if (list->next->data != data2 || list->next->next != NULL)
		return (1);
	ft_ll_clear(&list, free);
	return (0);
}
