/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:41:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:14:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

int	test_strrchr(void)
{
	char	*str;
	char	s;
	char	s2;
	char	*res;

	str = "Hello World!";
	s = 'o';
	s2 = 'z';
	res = ft_strrchr(str, s);
	if (res != str + 7)
		return (1);
	res = ft_strrchr(str, s2);
	if (res != NULL)
		return (2);
	res = ft_strrchr(str, '\0');
	if (res != str + ft_strlen(str))
		return (3);
	return (0);
}
