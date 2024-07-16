/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:01:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:49:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

/*
ft_dl_add_back(&list, ft_dl_create(data2));
// data-> data2
*/

int	t_dlfind(void)
{
	t_dlist	*list;
	t_dlist	*found_ret[3];
	int		*data;
	int		*data2;
	int		*data3;

	data3 = malloc(sizeof(int));
	*data3 = 21;
	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	found_ret[0] = ft_dl_find(list, data2, NULL);
	found_ret[1] = ft_dl_find(list, data3, NULL);
	found_ret[2] = ft_dl_find(list, data3, cmp_int);
	if (ft_dl_size(found_ret[0]) != 1 || found_ret[0]->data != data2)
		return (1);
	else if (found_ret[1] != NULL)
		return (1);
	else if (ft_dl_size(found_ret[2]) != 1 || found_ret[2]->data != data2)
		return (1);
	return (ft_dl_clear(&list, free), free(data3), 0);
}
