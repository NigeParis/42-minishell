/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:37:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:39:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"

#include <stdlib.h>

int	t_ll_push(void)
{
	t_list			*list;
	t_list			*list_rep1;
	t_list			*list_rep2;
	const int		data[][1] = {
	{42},
	{21}
	};

	list = NULL;
	list_rep1 = ft_ll_push(&list, &data[0]);
	list_rep2 = ft_ll_push(&list, &data[1]);
	if (!list || !list_rep1 || !list_rep2)
		return (1);
	else if (list != list_rep2)
		return (1);
	else if (list->next != list_rep1)
		return (1);
	else if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != &data[1] || list->next->data != &data[0])
		return (1);
	ft_ll_clear(&list, NULL);
	ft_ll_push(NULL, NULL);
	return (0);
}

int	t_ll_push_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_ll_push_back(&list, data);
	ft_ll_push_back(&list, data2);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next->data != data2)
		return (1);
	ft_ll_clear(&list, free);
	ft_ll_push_back(NULL, NULL);
	return (0);
}

int	t_ll_pop(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	*pop;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	pop = ft_ll_pop(&list);
	if (!list || ft_ll_size(list) != 1)
		return (1);
	else if (list->data != data2)
		return (1);
	else if (pop != data)
		return (1);
	ft_ll_clear(&list, free);
	free(pop);
	if (ft_ll_pop(&list) != NULL || ft_ll_pop(NULL) != NULL)
		return (1);
	return (0);
}

/*
	create_2elem_list(&list, (void **)&data, (void **)&data2); // (42)-> (21)-> NULL
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_ll_push(&list, data3); // (63)-> (42)-> (21)-> NULL
	pop = ft_ll_pop_back(&list); // 21 : (63)-> (42)-> NULL
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != data3)
		return (1);
	else if (list->next->data != data)
		return (1);
	else if (pop != data2)
		return (1);
	pop = ft_ll_pop_back(&list); // 42 : (63)-> NULL

*/
int	t_ll_pop_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		*data3;
	void	*pop;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_ll_push(&list, data3);
	pop = ft_ll_pop_back(&list);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (list->data != data3 || list->next->data != data || pop != data2)
		return (1);
	pop = ft_ll_pop_back(&list);
	if (ft_ll_size(list) != 1 || list->data != data3 || pop != data)
		return (1);
	pop = ft_ll_pop_back(&list);
	if (list != NULL || pop != data3 || ft_ll_size(list) != 0 || \
	ft_ll_pop_back(&list) != NULL)
		return (1);
	return (free(data), free(data2), free(data3), 0);
}
