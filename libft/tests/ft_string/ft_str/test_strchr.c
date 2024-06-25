/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:09:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strchr(void)
{
	char	*str;
	char	s;
	char	s2;
	char	*res;

	str = "Hello World!";
	s = 'o';
	s2 = 'z';
	res = ft_strchr(str, s);
	if (res != str + 4)
		return (1);
	res = ft_strchr(str, s2);
	if (res != NULL)
		return (2);
	res = ft_strchr(str, '\0');
	if (res != str + ft_strlen(str))
		return (3);
	return (0);
}
