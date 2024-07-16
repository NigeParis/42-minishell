/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_iterators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:04:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"

#include <stdlib.h>

int	t_dl_at(void)
{
	t_dlist	*list;
	t_dlist	*at;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	at = ft_dl_at(list, 1);
	if (at == NULL)
		return (1);
	else if (at->data != data2)
		return (1);
	else if (at->next != NULL)
		return (1);
	else if (at->prev != list)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dl_begin(void)
{
	t_dlist	*list;
	t_dlist	*begin;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	begin = ft_dl_begin(list->next);
	if (begin == NULL)
		return (1);
	else if (begin != list)
		return (1);
	else if (begin->data != data)
		return (1);
	else if (begin->next != list->next)
		return (1);
	else if (begin->prev != NULL)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dl_end(void)
{
	t_dlist	*list;
	t_dlist	*end;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	end = ft_dl_end(list);
	if (end == NULL)
		return (1);
	else if (end->data != data2)
		return (1);
	else if (end->next != NULL)
		return (1);
	else if (end->prev != list)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}
