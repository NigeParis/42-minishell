/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:03:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isint(void)
{
	if (ft_str_isint("23") != 1 || ft_str_isint("42") != 1 || \
	ft_str_isint("0") != 1 || ft_str_isint("-42") != 1 || \
	ft_str_isint("2147483647") != 1 || ft_str_isint("-2147483648") != 1)
		return (1);
	if (ft_str_isint("23.3") != 0 || ft_str_isint("42.0") != 0 || \
	ft_str_isint("0.0") != 0 || ft_str_isint("2.000000") != 0 || \
	ft_str_isint("0.000000") != 0 || ft_str_isint("2147483648") != 0 || \
	ft_str_isint("-2147483649") != 0 || ft_str_isint("2147483647.0") != 0 || \
	ft_str_isint("-2147483648.0") != 0)
		return (1);
	return (0);
}
