/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:44:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	t_ll_map(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*map;
	t_list	*map_err[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	map = ft_ll_map(list, add42_ret, free);
	map_err[0] = ft_ll_map(list, NULL, free);
	map_err[1] = ft_ll_map(NULL, add42_ret, free);
	map_err[2] = ft_ll_map(list, add42_ret, NULL);
	if (!map || *(int *)map->data != 84 || !map->next)
		return (1);
	else if (*(int *)map->next->data != 63)
		return (1);
	else if (map->next->next != NULL)
		return (1);
	else if (map_err[0] != NULL || map_err[1] != NULL || map_err[2] != NULL)
		return (1);
	ft_ll_clear(&list, free);
	ft_ll_clear(&map, free);
	return (0);
}
