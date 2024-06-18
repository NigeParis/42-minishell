/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:54:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_memcmp(void)
{
	const char	str[] = "1234567\0009";
	const char	str2[] = "1234567\0009";
	const char	str3[] = "1234567\000a";
	const char	str4[] = "1234567\0009";

	if (ft_memcmp(str, str2, 10) != 0)
		return (1);
	if (ft_memcmp(str, str3, 10) >= 0)
		return (2);
	if (ft_memcmp(str3, str, 10) <= 0)
		return (3);
	if (ft_memcmp(str, str2, 0) != 0)
		return (4);
	if (ft_memcmp(str, str4, 10) != 0)
		return (5);
	return (0);
}
