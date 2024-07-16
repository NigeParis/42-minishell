/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:27:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:47:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

int	t_ll_find(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		*data3;
	void	*found;

	data3 = malloc(sizeof(int));
	create_2elem_list(&list, (void **)&data, (void **)&data2);
	found = ft_ll_find(list, data2, NULL);
	if (!found || *(int *)found != *data2)
		return (1);
	*data3 = 63;
	found = ft_ll_find(list, data3, cmp_int);
	if (found != NULL)
		return (2);
	found = ft_ll_find(NULL, data2, NULL);
	if (found != NULL)
		return (3);
	*data3 = 42;
	found = ft_ll_find(list, data3, cmp_int);
	if (!found || *(int *)found != *data)
		return (4);
	ft_ll_clear(&list, free);
	free(data3);
	return (0);
}
