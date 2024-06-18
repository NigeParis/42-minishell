/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 17:13:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"

int	test_vec_apply(void)
{
	t_vector	*vec;
	int			i;

	i = 0;
	vec = ft_vec_new();
	ft_vec_add(&vec, &i);
	ft_vec_apply(vec, add42);
	if (*(int *)vec->datas[0] != 42)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
