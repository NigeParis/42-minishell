/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 15:40:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"

#include <stdlib.h>

void	**ft_vec_to_array(t_vector **vec)
{
	void	**array;

	if (!vec || !*vec)
		return (NULL);
	if (!(*vec)->count)
		return (free(*vec), NULL);
	if ((*vec)->count < (*vec)->cappacity)
		(*vec)->datas[(*vec)->count] = NULL;
	array = (*vec)->datas;
	free(*vec);
	return (array);
}
