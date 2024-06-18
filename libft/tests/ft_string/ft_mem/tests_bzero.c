/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:24:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:37:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_bzero(void)
{
	char		str[10];
	const char	str2[10] = {0};

	ft_strlcpy(str, "123456789", 10);
	ft_bzero(str, 10);
	if (ft_memcmp(str, str2, 10) != 0)
		return (1);
	return (0);
}
