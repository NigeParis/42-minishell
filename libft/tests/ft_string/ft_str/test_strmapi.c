/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:13:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>

static char	local_mapi(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	test_strmapi(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strmapi(str, &local_mapi);
	if (ft_strcmp(res, "hELLO wORLD!") != 0)
		return (1);
	free(res);
	return (0);
}
