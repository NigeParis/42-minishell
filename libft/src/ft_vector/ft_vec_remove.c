/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:03:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 12:41:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_vector.h"

void	ft_vec_remove(t_vector *vector, size_t n, void (*del)(void *))
{
	if (n >= vector->count)
		return ;
	if (del)
		del(vector->datas[n]);
	vector->datas[n] = NULL;
	ft_vec_shift(vector, n, 1);
}

void	ft_vec_remove_if(t_vector *vector, t_data_is func, t_data_apply del)
{
	size_t	i;

	i = 0;
	while (i < vector->count)
	{
		if (func(vector->datas[i]))
			ft_vec_remove(vector, i, del);
		else
			i++;
	}
}
