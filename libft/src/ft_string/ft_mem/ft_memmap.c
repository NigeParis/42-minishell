/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 14:20:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_memmap(void **src, size_t nb_e, t_data_tr f)
{
	void	**dst;
	size_t	i;

	if (!src || !f)
		return (NULL);
	dst = malloc((nb_e + 1) * sizeof(void *));
	if (!dst)
		return (NULL);
	dst[nb_e] = NULL;
	i = 0;
	while (i < nb_e)
	{
		dst[i] = f(src[i]);
		i++;
	}
	return (dst);
}
