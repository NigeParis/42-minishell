/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:06:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include <stdlib.h>

int	t_dl_new(void)
{
	t_dlist	*list;

	list = ft_dl_new();
	if (list == NULL)
		return (1);
	ft_dl_clear(&list, free);
	return (0);
}
