/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_islong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:10:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_islong(void)
{
	if (ft_str_islong("23") != 1 || ft_str_islong("42") != 1 || \
	ft_str_islong("0") != 1 || ft_str_islong("2") != 1 || \
	ft_str_islong("-34") != 1 || ft_str_islong("42") != 1 || \
	ft_str_islong("9223372036854775807") != 1 || \
	ft_str_islong("-9223372036854775808") != 1)
		return (1);
	if (ft_str_islong("9223372036854775808") != 0 || \
	ft_str_islong("-9223372036854775809") != 0 || \
	ft_str_islong("92233720368547758070") != 0 || \
	ft_str_islong("-92233720368547758080") != 0 || \
	ft_str_islong("9223372036854775807a") != 0 || \
	ft_str_islong("-9223372036854775808a") != 0 || \
	ft_str_islong("9223372036854775807 ") != 0 || \
	ft_str_islong("-9223372036854775808 ") != 0 || \
	ft_str_islong("-+0") != 0 || ft_str_islong("+-0") != 0 || \
	ft_str_islong("0-") != 0 || ft_str_islong("0+") != 0)
		return (2);
	return (0);
}
