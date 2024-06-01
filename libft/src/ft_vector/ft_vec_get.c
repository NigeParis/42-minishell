/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 09:33:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"

void	*ft_vec_get(t_vector *vector, const void *key, \
					int (*cmp)(const void *v_data, const void *key))
{
	size_t	i;

	i = 0;
	while (i < vector->count)
	{
		if (cmp(vector->datas[i], key) == 0)
			return (vector->datas[i]);
		i++;
	}
	return (NULL);
}
