/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:24 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:41:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_vec_cat(t_vector **vec_a, const t_vector *vec_b)
{
	size_t	i;

	i = 0;
	if ((*vec_a)->cappacity < ((*vec_a)->count + vec_b->count))
		return (false);
	while (i < vec_b->count)
	{
		(*vec_a)->datas[(*vec_a)->count + i] = vec_b->datas[i];
		i++;
	}
	(*vec_a)->count += i;
	return (true);
}
