/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:00:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include "ft_list_types.h"

#include <stdlib.h>

int	t_dlcreate(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	if (list == NULL)
		return (1);
	else if (list->data != data)
		return (1);
	else if (list->next != NULL)
		return (1);
	else if (list->prev != NULL)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}
