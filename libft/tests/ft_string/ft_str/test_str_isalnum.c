/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isalnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 15:16:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isalnum(void)
{
	if (ft_str_isalnum("HelloWorld42") != 1)
		return (1);
	if (ft_str_isalnum("Hello World42") != 0)
		return (2);
	if (ft_str_isalnum("Hello21World!") != 0)
		return (3);
	if (ft_str_isalnum("Hello420BlazeIt.") != 0)
		return (4);
	if (ft_str_isalnum("HelloWorld696969\0") != 1)
		return (5);
	if (ft_str_isalnum("") != 0)
		return (6);
	return (0);
}
