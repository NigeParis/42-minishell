/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:56:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_memcpy(void)
{
	char		str[10];
	const char	str3[] = "1234567\0009";

	ft_strlcpy(str, "123456789", 10);
	ft_memcpy(str, "abc", 3);
	if (ft_memcmp(str, "abc456789", 10) != 0)
		return (1);
	ft_memcpy(str, str3, 10);
	if (ft_memcmp(str, str3, 10) != 0)
		return (2);
	return (0);
}
