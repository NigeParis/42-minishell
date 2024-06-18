/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 20:44:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_new(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	if (vec->count != 0)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN)
		return (1);
	else if (vec->datas == NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
