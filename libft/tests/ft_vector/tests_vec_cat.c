/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:15:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 21:11:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include <stdbool.h>

/*
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ft_vec_add(&vec_b, &d); // 45
	ft_vec_add(&vec_b, &e); // 45 46
	ft_vec_add(&vec_b, &f); // 45 46 47
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
*/

void	init_vec_cat(t_vector **vec_a, t_vector **vec_b)
{
	*vec_a = ft_vec_from_size(6);
	ft_vec_add(vec_a, (void *)42);
	ft_vec_add(vec_a, (void *)43);
	ft_vec_add(vec_a, (void *)44);
	*vec_b = ft_vec_new();
	ft_vec_add(vec_b, (void *)45);
	ft_vec_add(vec_b, (void *)46);
	ft_vec_add(vec_b, (void *)47);
}

int	test_vec_cat(void)
{
	bool		ret;
	t_vector	*vec_a;
	t_vector	*vec_b;

	init_vec_cat(&vec_a, &vec_b);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != true || vec_a->count != 6)
		return (1);
	else if (ft_vec_at(vec_a, 0) != (void *)42 || ft_vec_at(vec_a, 1) != \
	(void *)43 || ft_vec_at(vec_a, 2) != (void *)44 || ft_vec_at(vec_a, 3) != \
	(void *)45 || ft_vec_at(vec_a, 4) != (void *)46 || ft_vec_at(vec_a, 5) != \
	(void *)47)
		return (2);
	ft_vec_destroy(&vec_a);
	vec_a = ft_vec_new();
	ft_vec_add(&vec_a, (void *)42);
	ft_vec_add(&vec_a, (void *)43);
	ft_vec_add(&vec_a, (void *)44);
	ret = ft_vec_cat(&vec_a, vec_b);
	if (ret != false || vec_a->count != 3)
		return (3);
	else if (ft_vec_at(vec_a, 0) != (void *)42 || ft_vec_at(vec_a, 1) != \
		(void *)43 || ft_vec_at(vec_a, 2) != (void *)44)
		return (4);
	return (ft_vec_destroy(&vec_a), ft_vec_destroy(&vec_b), 0);
}
