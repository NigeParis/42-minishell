/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:47:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 09:48:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_types.h"
#include <stddef.h>

void	ft_apply_2d(void **array, t_data_apply f)
{
	size_t	i;

	i = 0;
	while (array[i])
		f(array[i++]);
}
