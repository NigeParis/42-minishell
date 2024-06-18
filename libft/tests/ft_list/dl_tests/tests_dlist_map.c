/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:06:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:48:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	t_dl_map(void)
{
	t_dlist	*list;
	t_dlist	*map;
	t_dlist	*map2;
	int		*data1;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	map2 = ft_dl_map(list, NULL, free);
	map = ft_dl_map(list, add42_ret, free);
	if (map == NULL)
		return (1);
	else if (*(int *)map->data != 84)
		return (1);
	else if (map->next == NULL)
		return (1);
	else if (*(int *)map->next->data != 63)
		return (1);
	else if (map->next->next != NULL)
		return (1);
	else if (map2 != NULL)
		return (1);
	ft_dl_clear(&list, free);
	ft_dl_clear(&map, free);
	return (0);
}
