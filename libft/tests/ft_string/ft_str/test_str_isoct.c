/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isoct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:19:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isoct(void)
{
	if (ft_str_isoct("0o1234567") != 1 || ft_str_isoct("0O1234567") != 1 || \
	ft_str_isoct("0o342") != 1 || ft_str_isoct("0o0") != 1 || \
	ft_str_isoct("0o000000") != 1)
		return (1);
	if (ft_str_isoct("-0o1234568") != 0 || ft_str_isoct("0o1234568") != 0 || \
	ft_str_isoct("0o9") != 0 || ft_str_isoct("12") != 0 || \
	ft_str_isoct("-7") != 0 || ft_str_isoct("+67") != 0)
		return (2);
	return (0);
}
