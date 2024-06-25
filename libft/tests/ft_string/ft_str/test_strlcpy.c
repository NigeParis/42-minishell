/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:12:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

int	test_strlcpy(void)
{
	char	*str;
	char	*res;
	size_t	size;
	int		ret;

	str = "Hello World!";
	size = 15;
	res = malloc(sizeof(char) * size);
	ft_bzero(res, size);
	ret = ft_strlcpy(res, str, size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (1);
	free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is zod!", size);
	if (ft_strcmp(res, "This is zod!") != 0 || ret != 12)
		return (2);
	free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is too large!", size);
	if (ft_strncmp(res, "This is too large!", size - 1) != 0 || \
	ret != (int)ft_strlen("This is too large!"))
		return (3);
	free(res);
	return (0);
}
