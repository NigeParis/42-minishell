/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:29 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 09:34:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_clear(t_vector *vec)
{
	size_t	size;

	size = 0;
	while (size < vec->count)
		vec->datas[size++] = NULL;
	vec->count = 0;
}
