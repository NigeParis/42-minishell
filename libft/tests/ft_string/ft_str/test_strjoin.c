/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:10:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	test_right_empty(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str2)
		return (1);
	free(res);
	str2 = NULL;
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str)
		return (2);
	free(res);
	return (0);
}

static int	test_left_empty(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str2)
		return (1);
	free(res);
	str = NULL;
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str2)
		return (2);
	free(res);
	return (0);
}

int	test_strjoin(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!Hello World!") != 0)
		return (1);
	free(res);
	if (test_right_empty() != 0)
		return (20 + test_right_empty());
	if (test_left_empty() != 0)
		return (30 + test_left_empty());
	return (0);
}
