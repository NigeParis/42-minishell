/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:08:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 12:41:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vec_map(t_vector *vec, t_data_tr func)
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
