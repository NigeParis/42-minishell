/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:04:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 14:26:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"
#include <stdio.h>

void	*ft_vec_end(t_vector *vec)
{
	if (vec == NULL || vec->datas == NULL || vec->count == 0)
		return (NULL);
	return (vec->datas[vec->count - 1]);
}
