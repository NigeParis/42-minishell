/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:49:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:34:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_sqrt(void)
{
	double	x;
	double	result;

	x = 4;
	result = ft_sqrt(x);
	if (result > 2.01 || result < 1.99)
		return (1);
	x = 2;
	result = ft_sqrt(x);
	if (result > 1.42 || result < 1.41)
		return (2);
	x = -1;
	result = ft_sqrt(x);
	if (result >= -0.99 || result <= -1.01)
		return (3);
	return (0);
}
