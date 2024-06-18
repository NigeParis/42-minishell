/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_subrange.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:08 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:10:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_dl_subrange(void)
{
	t_dlist	*list;
	t_dlist	*sub;
	int		*data1;
	int		*data2;
	int		*data3;

	data3 = malloc(sizeof(int));
	*data3 = 63;
	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ft_dl_push_back(&list, data3);
	sub = ft_dl_subrange(list, list->next);
	if (ft_dl_size(sub) != 1 || sub->data != data1)
		return (1);
	ft_dl_clear(&sub, NULL);
	sub = ft_dl_subrange(list, list->next->next);
	if (ft_dl_size(sub) != 2 || sub->data != data1 || \
	sub->next->data != data2 || ft_dl_clear(&sub, NULL), 0)
		return (2);
	if (ft_dl_subrange(NULL, NULL) != NULL)
		return (3);
	sub = ft_dl_subrange(list, list);
	if (ft_dl_size(sub) != 1 || sub->data != data1)
		return (4);
	return (ft_dl_clear(&sub, NULL), ft_dl_clear(&list, free), 0);
}
