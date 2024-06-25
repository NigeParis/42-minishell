/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:08:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_split(void)
{
	const char	*str = "  Hello World!  ";
	char		**res;
	const char	*str2 = "Hello World!  ";
	char		**res2;
	size_t		i;

	res = ft_split(str, ' ');
	res2 = ft_split(str2, ' ');
	if (ft_strcmp(res[0], "Hello") != 0 || ft_strcmp(res[1], "World!") != 0
		|| res[2] != NULL)
		return (1);
	if (ft_strcmp(res2[0], "Hello") != 0 || ft_strcmp(res2[1], "World!") != 0
		|| res2[2] != NULL)
		return (2);
	i = 0;
	while (res[i] != NULL)
		free(res[i++]);
	i = 0;
	while (res2[i] != NULL)
		free(res2[i++]);
	return (free(res), free(res2), 0);
}
