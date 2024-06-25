/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isdouble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 15:43:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isdouble(void)
{
	if (ft_str_isdouble("23.3") != 1 || ft_str_isdouble("42") != 1 || \
	ft_str_isdouble(".22") != 1 || ft_str_isdouble("0.0") != 1 || \
	ft_str_isdouble("2.000000") != 1 || ft_str_isdouble("0.000000") != 1)
		return (1);
	if (ft_str_isdouble("34..4") != 0)
		return (2);
	if (ft_str_isdouble("0a.0") != 0 || ft_str_isdouble("0.0a") != 0)
		return (3);
	if (ft_str_isdouble("0.0.0") != 0)
		return (4);
	if (ft_str_isdouble("-") != 0 || ft_str_isdouble("+") != 0 || \
	ft_str_isdouble("-.") != 0 || ft_str_isdouble("+.") != 0)
		return (5);
	if (ft_str_isdouble("94308243208523048750743") != 0 || \
	ft_str_isdouble("") != 0 || ft_str_isdouble(".") != 0)
		return (6);
	return (0);
}
