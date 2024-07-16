/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:40:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:41:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"

#include <stdlib.h>

int	t_ll_rev(void)
{
	t_list	*list;
	t_list	*rev;
	int		*data;
	int		*data2;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	rev = ft_ll_rev(&list);
	if (ft_ll_size(list) != 2)
		return (1);
	else if (rev->data != data2)
		return (1);
	else if (rev->next->data != data)
		return (1);
	ft_ll_clear(&rev, free);
	rev = NULL;
	rev = ft_ll_rev(NULL);
	if (rev != NULL || ft_ll_rev(&rev) != NULL)
		return (1);
	return (0);
}
