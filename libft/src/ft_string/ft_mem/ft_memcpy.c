/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:48:06 by bgoulard          #+#    #+#             */
/*   Updated: 2023/11/10 16:16:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret;

	ret = dest;
	if (dest == src)
		return (dest);
	while (n--)
		((char *)dest)[n] = ((const char *)src)[n];
	return (ret);
}
