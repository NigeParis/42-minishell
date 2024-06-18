/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:22:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 20:44:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_at(void)
{
	t_vector	*vec;
	int			a;
	int			b;
	int			c;

	a = 0;
	b = 1;
	c = 2;
	vec = ft_vec_new();
	ft_vec_add(&vec, &a);
	ft_vec_add(&vec, &b);
	ft_vec_add(&vec, &c);
	if (*(int *)ft_vec_at(vec, 0) != 0)
		return (1);
	else if (*(int *)ft_vec_at(vec, 1) != 1)
		return (1);
	else if (*(int *)ft_vec_at(vec, 2) != 2)
		return (1);
	else if (ft_vec_at(vec, 3) != NULL)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}
