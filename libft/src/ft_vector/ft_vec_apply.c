/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:09:28 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_apply(t_vector *vec, void (*func)(void *))
{
	size_t	i;

	i = 0;
	while (i < vec->count)
		func(vec->datas[i++]);
	return ;
}
