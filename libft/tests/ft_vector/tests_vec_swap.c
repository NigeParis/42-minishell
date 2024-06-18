/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 21:18:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_swap(void)
{
	t_vector	*vec;
	void		*data[3];
	int			arr[3];

	arr[0] = 42;
	arr[1] = 43;
	arr[2] = 44;
	data[0] = (void *)&arr[0];
	data[1] = (void *)&arr[1];
	data[2] = (void *)&arr[2];
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_swap(vec, 0, 2);
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 44)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 42)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
