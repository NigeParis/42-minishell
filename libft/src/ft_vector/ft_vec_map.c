/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:08:55 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:38:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vec_map(t_vector *vec, void *(*func)(void *))
{
	t_vector	*ret;
	size_t		i;

	i = 0;
	ret = ft_vec_from_size(vec->count);
	if (!ret)
		return (NULL);
	while (i < vec->count)
	{
		ret->datas[i] = func(vec->datas[i]);
		i++;
	}
	ret->count = i;
	return (ret);
}
