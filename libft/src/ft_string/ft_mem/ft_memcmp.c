/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/11/10 15:59:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (index != n && ((const unsigned char *)s1)[index] == \
		((const unsigned char *)s2)[index])
		index++;
	if (index == n)
		index--;
	return (((unsigned char *)s1)[index] - ((unsigned char *)s2)[index]);
}
