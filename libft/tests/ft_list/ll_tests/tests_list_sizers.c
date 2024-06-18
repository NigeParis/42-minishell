/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_sizers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:43:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:46:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	t_ll_size(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_ll_size(NULL);
	size_ret[1] = ft_ll_size(list->next);
	size_ret[2] = ft_ll_size(list);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 2)
		return (1);
	ft_ll_clear(&list, free);
	return (0);
}

int	t_ll_size_match(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_ll_size_match(NULL, is42);
	size_ret[1] = ft_ll_size_match(list, is42);
	size_ret[2] = ft_ll_size_match(list->next, is42);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 0)
		return (1);
	ft_ll_clear(&list, free);
	return (0);
}
