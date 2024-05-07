/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:51 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 09:45:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_filter(t_vector *vec, bool (*func)(void *), void (*del)(void *))
{
	size_t	i;
	size_t	shift_count;

	i = 0;
	while (vec->count > i)
	{
		shift_count = 0;
		while (vec->count > i && func(vec->datas[i]) == false)
		{
			if (del)
				del(vec->datas[i]);
			shift_count++;
			vec->datas[i++] = NULL;
		}
		ft_vec_shift(vec, i - shift_count, shift_count);
		while (vec->count > i && func(vec->datas[i]) == true)
			i++;
	}
	return ;
}
