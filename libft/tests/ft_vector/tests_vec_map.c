/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:45 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 21:12:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

int	test_vec_map(void)
{
	t_vector	*vec;
	t_vector	*ret;
	int			**arr;

	arr = (int **)creat_tb();
	vec = ft_vec_from_array((void **)arr, 3);
	ret = ft_vec_map(vec, add42_ret);
	if (ret->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(ret, 0) != 84 || *(int *)ft_vec_at(ret, 1) != 85
		|| *(int *)ft_vec_at(ret, 2) != 86)
		return (2);
	ft_vec_apply(ret, free);
	ft_vec_destroy(&vec);
	ft_vec_destroy(&ret);
	return (0);
}
