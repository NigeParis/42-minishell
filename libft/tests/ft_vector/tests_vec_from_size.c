/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_from_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:00 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:20:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_from_size(void)
{
	t_vector	*vec;

	vec = ft_vec_from_size(42);
	if (vec->count != 0)
		return (1);
	else if (vec->cappacity != 42)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
