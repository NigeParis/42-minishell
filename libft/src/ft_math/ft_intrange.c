/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:22:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:11:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_range(int x, int min, int max, int new_max)
{
	int	res;

	if (max == min || new_max == 0 || min >= max)
		return (0);
	if (x <= min)
		return (0);
	if (x >= max)
		return (new_max);
	res = x - min;
	max -= min;
	return ((int)(((double)res / max) * new_max));
}

float	ft_range_f(float x, float min, float max, float new_max)
{
	return ((float)ft_range_d(x, min, max, new_max));
}

double	ft_range_d(double x, double min, double max, double new_max)
{
	double	res;

	if (max == min || new_max == 0 || min >= max)
		return (0);
	if (x <= min)
		return (0);
	if (x >= max)
		return (new_max);
	res = x - min;
	max -= min;
	return ((res / max) * new_max);
}
