/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:12:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isnum(void)
{
	if (ft_str_isnum("-23") != 1 || ft_str_isnum("+42") != 1 || \
	ft_str_isnum("0") != 1 || ft_str_isnum("2345865785645643532453") != 1 || \
	ft_str_isnum("2147483647") != 1)
		return (1);
	if (ft_str_isnum("23.3") != 0 || ft_str_isnum("42.0") != 0 || \
	ft_str_isnum("0.0") != 0 || ft_str_isnum("2.000000") != 0 || \
	ft_str_isnum("0.000000") != 0 || ft_str_isnum("--2147483648") != 0 || \
	ft_str_isnum("++2147483648") != 0)
		return (2);
	return (0);
}
