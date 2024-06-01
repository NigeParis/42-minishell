/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:02:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 21:03:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_vector.h"

static void	ft_loc_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

void	ft_vec_sort(t_vector *vec, t_data_cmp cmp_f)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < vec->count)
	{
		j = i + 1;
		while (j < vec->count)
		{
			if (cmp_f(vec->datas[i], vec->datas[j]) > 0)
				ft_loc_swap(&vec->datas[i], &vec->datas[j]);
			j++;
		}
		i++;
	}
	return ;
}
