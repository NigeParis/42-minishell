/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:55:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/01 16:31:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	const size_t	len_small = ft_strlen(small);
	const size_t	len_big = n;

	if ((!big || !small) && n == 0)
		return (NULL);
	while (n-- > len_small && big && *big)
		if (ft_strncmp(big++, small, len_small) == 0)
			return ((char *)big - 1);
	if (len_big >= len_small && ft_strncmp(big, small, len_small) == 0)
		return ((char *)big);
	return (NULL);
}
