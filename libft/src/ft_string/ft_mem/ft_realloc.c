/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:27:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:06:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

// direct call to malloc as ft_bzero is not needed
//  >> we are copying the content of ptr to new
void	*ft_realloc(void *ptr, size_t sizeNew, size_t sizeOld)
{
	void	*new;

	new = malloc(sizeNew);
	if (new == NULL)
		return (NULL);
	if (ptr == NULL)
		return (new);
	ft_memcpy(new, ptr, ft_min(sizeNew, sizeOld));
	free(ptr);
	return (new);
}
