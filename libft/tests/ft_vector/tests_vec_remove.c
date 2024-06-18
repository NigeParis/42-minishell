/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:13:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:55:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include <stdlib.h>

// tests vector has removed the arr[2]orrect element
// and
// tests vector_remove is bound checked with 42's call
static int	checks_01(t_vector *vec)
{
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42 || \
	*(int *)ft_vec_at(vec, 1) != 44)
		return (2);
	ft_vec_remove(vec, 42, NULL);
	if (vec->count != 2)
		return (3);
	return (0);
}

// tests vector_remove calls free on the correct element
static int	checks_02(t_vector *vec, const int *arr)
{
	if (vec->count != 2)
		return (1);
	if (*(int *)ft_vec_at(vec, 0) != arr[0] || *(int *)ft_vec_at(vec, 1) != \
	arr[2])
		return (1);
	return (0);
}

int	test_vec_remove(void)
{
	t_vector	*vec;
	const int	arr[3] = {42, 43, 44};
	int			*ptr;
	size_t		i;

	i = 0;
	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&arr[0]);
	ft_vec_add(&vec, (void *)&arr[1]);
	ft_vec_add(&vec, (void *)&arr[2]);
	ft_vec_remove(vec, 1, NULL);
	if (checks_01(vec))
		return (checks_01(vec));
	ft_vec_destroy(&vec);
	vec = ft_vec_new();
	while (i < 3)
	{
		ptr = (int *)malloc(sizeof(int));
		*ptr = arr[i++];
		ft_vec_add(&vec, (void *)ptr);
	}
	ft_vec_remove(vec, 1, free);
	if (checks_02(vec, arr))
		return (checks_02(vec, arr));
	return (ft_vec_apply(vec, free), ft_vec_destroy(&vec), 0);
}
