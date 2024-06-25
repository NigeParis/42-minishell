/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:15:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strtok(void)
{
	char	test[43];
	char	lorem[30];

	ft_strlcpy(lorem, "Lorem ipsum dolor ", 30);
	ft_strlcpy(test, "path/to/file:another/path:yet/another/path", 43);
	if (ft_strcmp(ft_strtok(lorem, " "), "Lorem") != 0
		|| ft_strcmp(ft_strtok(NULL, " "), "ipsum") != 0
		|| ft_strcmp(ft_strtok(NULL, " "), "dolor") != 0)
		return (1);
	if (ft_strcmp(ft_strtok(NULL, " "), "") != 0 || ft_strtok(NULL,
			" ") != NULL)
		return (2);
	if (ft_strcmp(ft_strtok(test, ":"), "path/to/file") != 0
		|| ft_strcmp(ft_strtok(NULL, ":"), "another/path") != 0)
		return (3);
	if (ft_strcmp(ft_strtok(NULL, ":/"), "yet") != 0)
		return (4);
	if (ft_strcmp(ft_strtok(NULL, ":/"), "another") != 0)
		return (5);
	return (0);
}
