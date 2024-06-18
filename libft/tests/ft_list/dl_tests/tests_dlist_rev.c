/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:08:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:08:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

int	t_dl_rev(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*original_data1;
	int		*original_data2;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	original_data1 = data1;
	original_data2 = data2;
	ft_dl_rev(&list);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (list->data != original_data2 || list->next->data != original_data1)
		return (1);
	ft_dl_clear(&list, free);
	if (ft_dl_rev(NULL) != NULL)
		return (1);
	list = NULL;
	if (ft_dl_rev(&list) != NULL)
		return (1);
	return (0);
}
