/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:23:12 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:58:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

bool	ft_vec_shrink(t_vector *vec)
{
	void	**new_datas;
	size_t	i;

	if (vec->count == vec->cappacity)
		return (true);
	new_datas = ft_calloc(sizeof(void *), vec->count);
	if (!new_datas)
		return (false);
	i = 0;
	while (i < vec->count)
	{
		new_datas[i] = vec->datas[i];
		i++;
	}
	free(vec->datas);
	vec->datas = new_datas;
	vec->cappacity = vec->count;
	return (true);
}
