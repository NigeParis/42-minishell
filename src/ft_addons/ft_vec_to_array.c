/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 08:03:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"
#include <stdlib.h>

void	**ft_vec_to_array(t_vector **vec)
{
	void	**array;

	array = (*vec)->datas;
	free(*vec);
	return (array);
}
