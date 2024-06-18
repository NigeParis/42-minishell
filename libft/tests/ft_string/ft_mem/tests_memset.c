/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:01:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
	// ignore warning for memset args
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wmemset-transposed-args"
*/
int	test_memset(void)
{
	char	str[10];
	char	str2[10];

	ft_strlcpy(str, "123456789", 10);
	ft_strlcpy(str2, "123456789", 10);
	ft_memset(str, 'a', 10);
	if (ft_memcmp(str, "aaaaaaaaaa", 10) != 0)
		return (1);
	ft_memset(str, 'b', 0);
	if (ft_memcmp(str, "aaaaaaaaaa", 10) != 0)
		return (2);
	ft_memset(str, 'c', 5);
	if (ft_memcmp(str, "cccccaaaaa", 10) != 0)
		return (3);
	return (0);
}
