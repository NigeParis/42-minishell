/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_ishex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 23:52:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_ishex(void)
{
	if (ft_str_ishex("0123456789abcdefABCDEF") != 1)
		return (1);
	if (ft_str_ishex("0xdeadbeef") != 1 || ft_str_ishex("0xDEADBEEF") != 1)
		return (2);
	if (ft_str_ishex("0xdeadbeefg") != 0 || ft_str_ishex("0xDEADBEEFG") != 0)
		return (3);
	if (ft_str_ishex("0x") != 0 || ft_str_ishex("0X") != 0)
		return (4);
	if (ft_str_ishex("0x+32") != 0 || ft_str_ishex("0x-32") != 0)
		return (5);
	if (ft_str_ishex("0x0x") != 0 || ft_str_ishex("0X0X") != 0)
		return (6);
	if (ft_str_ishex("-0x0") != 0 || ft_str_ishex("+0X0") != 0)
		return (7);
	if (ft_str_ishex("0x0") != 1 || ft_str_ishex("0X0") != 1)
		return (8);
	if (ft_str_ishex("") != 0)
		return (8);
	return (0);
}
