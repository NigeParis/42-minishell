/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_shrink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 20:43:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

/*
// try to shrink an already shrunk vector
	ft_vec_shrink(vec);
*/

int	test_vec_shrink(void)
{
	t_vector	*vec;
	void		*data[3];
	int			numbers[3];

	numbers[0] = 42;
	numbers[1] = 43;
	numbers[2] = 44;
	data[0] = (void *)&numbers[0];
	data[1] = (void *)&numbers[1];
	data[2] = (void *)&numbers[2];
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_shrink(vec);
	if (vec->count != 3 || vec->cappacity != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42 || *(int *)ft_vec_at(vec, 1) != \
	43 || *(int *)ft_vec_at(vec, 2) != 44)
		return (1);
	ft_vec_shrink(vec);
	if (!vec || !vec->datas || !vec->cappacity || !vec->count || \
	vec->count != vec->cappacity || vec->count != 3)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
