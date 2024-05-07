/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:11 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 16:53:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vec_swap(t_vector *vec, size_t a, size_t b)
{
	void	*tmp;

	tmp = vec->datas[a];
	vec->datas[a] = vec->datas[b];
	vec->datas[b] = tmp;
}
