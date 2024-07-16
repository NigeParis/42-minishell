/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 11:24:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

int	test_strnstr(void)
{
	char	*str;
	char	*res;

	str = "The cake is a lie !\0I'm hidden lol\n";
	res = ft_strnstr(str, "The cake is a lie !", 100);
	if (res != str)
		return (1);
	res = ft_strnstr(str, "The cake is a lie !", 20);
	if (res != str)
		return (2);
	res = ft_strnstr(str, "The cake is a lie !", 19);
	if (res == NULL)
		return (3);
	res = ft_strnstr(str, "The cake is a lie !", 0);
	if (res != NULL)
		return (4);
	res = ft_strnstr(str, "hidden", 100);
	if (res != NULL)
		return (5);
	return (0);
}
