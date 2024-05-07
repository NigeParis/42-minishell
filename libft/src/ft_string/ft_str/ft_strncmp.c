/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:56:17 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/13 08:25:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	size_t				index;

	index = 0;
	if (n == 0)
		return (0);
	while (str1[index] == str2[index] && str1[index] && index < n - 1)
		index++;
	return (str1[index] - str2[index]);
}
