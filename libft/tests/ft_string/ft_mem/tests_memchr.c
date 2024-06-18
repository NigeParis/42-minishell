/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:18:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_memchr(void)
{
	char	str[10];

	ft_strlcpy(str, "1234567", 10);
	ft_strlcat(str, "890", 10);
	if (ft_memchr(str, '8', 10) != &str[7])
		return (1);
	if (ft_memchr(str, '9', 10) != &str[8])
		return (2);
	if (ft_memchr(str, 'z', 10) != NULL)
		return (3);
	if (ft_memchr(str, '7', 10) != &str[6])
		return (4);
	if (ft_memchr(str, '7', 0) != NULL)
		return (5);
	return (0);
}
