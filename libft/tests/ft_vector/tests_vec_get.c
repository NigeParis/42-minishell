/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:41:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

static int	cmp_fun(const void *v_data, const void *key)
{
	return (ft_strcmp(v_data, key));
}

int	test_vec_get(void)
{
	t_vector	*vector;
	void		*data_ret;

	vector = ft_vec_new();
	ft_vec_add(&vector, "Hello");
	ft_vec_add(&vector, "world");
	ft_vec_add(&vector, "this");
	ft_vec_add(&vector, "is");
	ft_vec_add(&vector, "Zod");
	data_ret = ft_vec_get(vector, "world", cmp_fun);
	if (ft_strcmp(data_ret, "world") != 0)
		return (1);
	data_ret = ft_vec_get(vector, "Zod", cmp_fun);
	if (ft_strcmp(data_ret, "Zod") != 0)
		return (1);
	data_ret = ft_vec_get(vector, "not here", cmp_fun);
	if (data_ret != NULL)
		return (1);
	ft_vec_destroy(&vector);
	return (0);
}
