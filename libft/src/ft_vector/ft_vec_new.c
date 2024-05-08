/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 13:42:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include <stdlib.h>

t_vector	*ft_vec_new(void)
{
	return (ft_vec_from_size(FT_VECTOR_BASE_LEN));
}

t_vector	*ft_vec_from_size(size_t n)
{
	t_vector	*ret;

	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	ret->datas = ft_calloc(sizeof(void *), n);
	if (!ret->datas)
		return (free(ret), NULL);
	ret->cappacity = n;
	ret->count = 0;
	return (ret);
}

t_vector	*ft_vec_from_array(void **data, size_t count)
{
	t_vector	*ret;
	size_t		i;

	if (count < FT_VECTOR_BASE_LEN)
		ret = ft_vec_from_size(FT_VECTOR_BASE_LEN);
	else
		ret = ft_vec_from_size(count);
	i = 0;
	while (i < count)
	{
		ret->datas[i] = data[i];
		i++;
	}
	ret->count = i;
	return (ret);
}

t_vector	*ft_vec_convert_alloccarray(void **data, size_t count)
{
	t_vector	*ret;

	ret = ft_calloc(sizeof(t_vector), 1);
	if (!ret)
		return (ret);
	ret->datas = data;
	ret->count = count;
	ret->cappacity = count;
	return (ret);
}
