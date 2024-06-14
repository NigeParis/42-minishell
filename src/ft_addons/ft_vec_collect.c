/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:36:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 17:51:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_vector.h"
#include "ft_vector_types.h"

void	*ft_vec_collect(t_vector **vec, void *(*f)(const void *c_val, \
											   const void *d_val))
{
	size_t	i;
	void	*data;

	i = 0;
	data = NULL;
	while (i < (*vec)->count)
		data = f(data, ft_vec_at(*vec, i++));
	ft_vec_destroy(vec);
	return (data);
}
