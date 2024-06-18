/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_len_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:11:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 00:15:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_len_2d(void)
{
	char	*arr2d[4];

	arr2d[0] = "Hello";
	arr2d[1] = "World";
	arr2d[2] = "!";
	arr2d[3] = NULL;
	if (ft_len_2d((const void *const *)arr2d) != 3)
		return (1);
	return (0);
}
