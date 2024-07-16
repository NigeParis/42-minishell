/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_test_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:08:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 14:27:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"

#include <stdlib.h>

void	create_2elem_list(t_list **list, void **data1, void **data2)
{
	*data1 = malloc(sizeof(int));
	*data2 = malloc(sizeof(int));
	*(int *)*data1 = 42;
	*(int *)*data2 = 21;
	*list = NULL;
	ft_ll_push(list, *data1);
	ft_ll_push_back(list, *data2);
}
