/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 21:04:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"

int	test_vec_sort(void)
{
	t_vector	*vec;
	int			nbrs[3];

	nbrs[0] = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&nbrs[0]);
	nbrs[1] = 43;
	ft_vec_add(&vec, (void *)&nbrs[1]);
	nbrs[2] = 42;
	ft_vec_add(&vec, (void *)&nbrs[2]);
	ft_vec_sort(vec, cmp_int);
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (2);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (3);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (4);
	ft_vec_destroy(&vec);
	return (0);
}
