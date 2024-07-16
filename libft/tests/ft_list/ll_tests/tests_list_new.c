/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:37:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:39:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"

#include <stdlib.h>

int	t_ll_new(void)
{
	t_list	*list;

	list = ft_ll_new();
	if (!list)
		return (1);
	free(list);
	return (0);
}
