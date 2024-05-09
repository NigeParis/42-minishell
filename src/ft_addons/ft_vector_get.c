/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 14:25:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"

void	*ft_vector_get(t_vector *vector, const void *key, \
					int (*cmp)(const void *, const void *))
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
