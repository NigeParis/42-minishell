/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:30:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_reserve(void)
{
	t_vector	*vec;
	bool		ret[3];

	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret[0] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN - 2);
	ret[1] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN);
	ret[2] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 2);
	if (ret[0] != true)
		return (1);
	else if (ret[1] != true)
		return (1);
	else if (ret[2] == false)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN + 2)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
