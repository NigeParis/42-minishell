/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:26:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:26:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strlen(void)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = "Hello World!";
	str2 = "";
	str3 = "Hello\0World!";
	if (ft_strlen(str) != 12)
		return (1);
	if (ft_strlen(str2) != 0)
		return (2);
	if (ft_strlen(str3) != 5)
		return (3);
	return (0);
}
