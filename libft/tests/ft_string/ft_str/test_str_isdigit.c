/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 15:28:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isdigit(void)
{
	if (ft_str_isdigit("00000000000000000000012") != 1)
		return (1);
	if (ft_str_isdigit("1234567890q") != 0)
		return (2);
	if (ft_str_isdigit("8^)") != 0)
		return (3);
	if (ft_str_isdigit("42.5") != 0)
		return (4);
	if (ft_str_isdigit("+00") != 0)
		return (5);
	if (ft_str_isdigit("") != 0)
		return (6);
	return (0);
}
