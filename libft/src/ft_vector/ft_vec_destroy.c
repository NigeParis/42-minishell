/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:20 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 10:07:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

bool	ft_vec_destroy(t_vector **vec)
{
	(*vec)->count = 0;
	(*vec)->cappacity = 0;
	free((*vec)->datas);
	free(*vec);
	*vec = NULL;
	return (true);
}
