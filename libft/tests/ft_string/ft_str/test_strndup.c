/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:23:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:13:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strndup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strndup(str, 5);
	if (ft_strcmp(res, "Hello") != 0)
		return (1);
	free(res);
	res = ft_strndup(str, 0);
	if (ft_strcmp(res, "") != 0)
		return (2);
	free(res);
	res = ft_strndup(str, 12);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (3);
	free(res);
	res = ft_strndup(str, 15);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (4);
	free(res);
	return (0);
}
