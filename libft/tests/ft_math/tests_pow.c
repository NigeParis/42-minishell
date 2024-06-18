/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_pow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:21:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 01:01:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_pow(void)
{
	size_t	x;
	size_t	y;

	x = 2;
	y = 3;
	if (ft_pow(x, y) != 8)
		return (1);
	y = 0;
	if (ft_pow(x, y) != 1)
		return (1);
	y = 1;
	if (ft_pow(x, y) != 2)
		return (1);
	if (ft_pow(0, y) != 0)
		return (1);
	return (0);
}
