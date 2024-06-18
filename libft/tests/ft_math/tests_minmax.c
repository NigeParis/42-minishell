/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:49:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 00:54:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_min(void)
{
	const int	a = 1;
	const int	b = 2;
	const int	c = 3;

	if (ft_min(a, b) != a)
		return (1);
	if (ft_min(b, c) != b)
		return (1);
	return (0);
}

int	test_ft_max(void)
{
	const int	a = 1;
	const int	b = 2;
	const int	c = 3;

	if (ft_max(a, b) != b)
		return (1);
	if (ft_max(c, b) != c)
		return (1);
	return (0);
}
