/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:11:28 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 09:24:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_shift(t_vector *vec, size_t start, size_t shift)
{
	while (start + shift < vec->count)
	{
		vec->datas[start] = vec->datas[start + shift];
		start++;
	}
	vec->count -= shift;
}
