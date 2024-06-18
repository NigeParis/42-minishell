/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:13:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_add(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)42);
	if (vec->count != 1)
		return (1);
	if (vec->datas[0] != (void *)42)
		return (1);
	ft_vec_add(&vec, (void *)43);
	ft_vec_add(&vec, (void *)44);
	ft_vec_add(&vec, (void *)45);
	ft_vec_add(&vec, (void *)46);
	ft_vec_add(&vec, (void *)47);
	if (vec->count != 6)
		return (1);
	if (vec->datas[0] != (void *)42 || vec->datas[1] != (void *)43 || \
	vec->datas[2] != (void *)44 || vec->datas[3] != (void *)45 || \
	vec->datas[4] != (void *)46 || vec->datas[5] != (void *)47)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
