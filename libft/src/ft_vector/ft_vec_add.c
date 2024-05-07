/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:23 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 09:49:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_vec_add(t_vector **vec, void *data)
{
	size_t	nw_size;

	if ((*vec)->count == (*vec)->cappacity)
	{
		nw_size = (*vec)->cappacity + FT_VECTOR_BASE_LEN;
		if (ft_vec_reserve(vec, nw_size) == false)
			return (false);
	}
	(*vec)->datas[(*vec)->count++] = data;
	return (true);
}
