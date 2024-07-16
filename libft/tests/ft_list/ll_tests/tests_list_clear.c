/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_listclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:21:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:22:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "tests/ll_tests.h"

#include <stdlib.h>

int	t_ll_clear(void)
{
	t_list	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_ll_create(data);
	ft_ll_clear(&list, NULL);
	list = ft_ll_create(data);
	ft_ll_clear(&list, free);
	ft_ll_clear(NULL, NULL);
	return (0);
}
