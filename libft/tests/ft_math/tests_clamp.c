/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:46:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 09:12:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_clamp(void)
{
	const int	max = 42;
	const int	min = 21;
	int			x;

	x = 0;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp(x, min, max) != x)
		return (1);
	return (0);
}

int	test_ft_clamp_f(void)
{
	const float	max = 42.0;
	const float	min = 21.0;
	float		x;

	x = 0;
	if (ft_clamp_f(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp_f(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp_f(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp_f(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp_f(x, min, max) != x)
		return (1);
	return (0);
}

int	test_ft_clamp_d(void)
{
	const double	max = 42.0;
	const double	min = 21.0;
	double			x;

	x = 0;
	if (ft_clamp_d(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp_d(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp_d(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp_d(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp_d(x, min, max) != x)
		return (1);
	return (0);
}
