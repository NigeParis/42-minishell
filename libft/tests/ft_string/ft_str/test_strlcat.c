/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:11:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

int	test_strlcat(void)
{
	char	*str;
	char	*str2;
	char	*res;
	size_t	size;
	int		ret;

	str = "Hello";
	str2 = " World!";
	size = 15;
	res = malloc(sizeof(char) * size);
	ft_bzero(res, size);
	ret = ft_strlcat(res, str, size);
	if (ft_strcmp(res, "Hello") != 0 || ret != 5)
		return (1);
	ret = ft_strlcat(res, str2, size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (2);
	ret = ft_strlcat(res, "This is zod!", size);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 24)
		return (3);
	free(res);
	return (0);
}
