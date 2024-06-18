/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_subrange.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:44:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:46:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

/*
	ft_ll_push(&list, data); // (42)-> NULL
	ft_ll_push(&list, data2); // (21)-> (42)-> NULL
	sub = ft_ll_subrange(list, list->next); // (21)-> NULL
	sub = ft_ll_subrange(list, NULL); // (21)-> (42)-> NULL
	sub = ft_ll_subrange(list, (const t_list *)data2); // (21)-> (42)-> NULL
*/

int	t_ll_subrange(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*sub;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	ft_ll_rev(&list);
	sub = ft_ll_subrange(list, list->next);
	if (ft_ll_size(sub) != 1 || sub->data != data2)
		return (1);
	ft_ll_clear(&sub, NULL);
	sub = ft_ll_subrange(list, NULL);
	if (ft_ll_size(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (2);
	ft_ll_clear(&sub, NULL);
	sub = ft_ll_subrange(list, (const t_list *)data2);
	if (ft_ll_size(sub) != 2 || sub->data != data2 || sub->next->data != data)
		return (3);
	ft_ll_clear(&sub, NULL);
	if (ft_ll_subrange(NULL, NULL) != NULL)
		return (4);
	sub = ft_ll_subrange(list, list);
	if (ft_ll_size(sub) != 1 || sub->data != data2)
		return (5);
	return (ft_ll_clear(&sub, NULL), ft_ll_clear(&list, free), 0);
}
