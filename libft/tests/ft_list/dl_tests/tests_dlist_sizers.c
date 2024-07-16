/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_sizers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:09:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:48:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

int	t_dl_size(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	size_ret[0] = ft_dl_size(NULL);
	size_ret[1] = ft_dl_size(list->next);
	size_ret[2] = ft_dl_size(list);
	if (size_ret[0] != 0)
		return (1);
	else if (size_ret[1] != 1)
		return (1);
	else if (size_ret[2] != 2)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dl_size_of_data(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	size_ret[0] = ft_dl_size_of_data(NULL, is42);
	size_ret[1] = ft_dl_size_of_data(list->next, is42);
	size_ret[2] = ft_dl_size_of_data(list, is42);
	if (size_ret[0] != 0)
		return (1);
	else if (size_ret[1] != 0)
		return (2);
	else if (size_ret[2] != 1)
		return (3);
	ft_dl_clear(&list, free);
	return (0);
}
