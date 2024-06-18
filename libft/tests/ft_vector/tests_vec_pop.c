/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:47:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 13:56:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include <stdio.h>

int	test_vec_pop(void)
{
	t_vector	*vec;
	const char	*str;

	vec = ft_vec_new();
	ft_vec_add(&vec, "value1");
	ft_vec_add(&vec, "value2");
	ft_vec_add(&vec, "value3");
	str = ft_vec_pop(vec);
	if (str == NULL || ft_strcmp(str, "value3") != 0 || vec->count != 2)
		return (1);
	str = ft_vec_pop(vec);
	if (str == NULL || ft_strcmp(str, "value2") != 0 || vec->count != 1)
		return (2);
	str = ft_vec_pop(vec);
	if (str == NULL || ft_strcmp(str, "value1") != 0 || vec->count != 0)
		return (3);
	str = ft_vec_pop(vec);
	if (str != NULL)
		return (4);
	return (ft_vec_destroy(&vec), 0);
}
