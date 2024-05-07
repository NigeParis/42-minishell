/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:49 by bgoulard          #+#    #+#             */
/*   Updated: 2023/11/12 12:11:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest > src)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	else
		while (i++ != n)
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
	return (dest);
}
