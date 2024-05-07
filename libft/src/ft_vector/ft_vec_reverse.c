/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:29:24 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 19:29:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_reverse(t_vector *vector)
{
	size_t	i;
	size_t	j;
	void	*tmp;

	i = 0;
	j = vector->count - 1;
	while (i < j)
	{
		tmp = vector->datas[i];
		vector->datas[i] = vector->datas[j];
		vector->datas[j] = tmp;
		i++;
		j--;
	}
}
