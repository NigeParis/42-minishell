/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isfloat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 23:54:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isfloat(void)
{
	if (ft_str_isfloat("23.3") != 1 || ft_str_isfloat("42") != 1 || \
	ft_str_isfloat(".22") != 1 || ft_str_isfloat("0.0") != 1 || \
	ft_str_isfloat("2.000000") != 1 || ft_str_isfloat("0.000000") != 1)
		return (1);
	return (0);
}
