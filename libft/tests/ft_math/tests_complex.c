/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:46:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:08:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_math_types.h"

int	test_ft_complex_abs(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	const t_complex	z = {42, 42};
	double			res;

	res = ft_complex_abs(x);
	if (res < 41.99 || res > 42.01)
		return (1);
	res = ft_complex_abs(y);
	if (res < 41.99 || res > 42.01)
		return (2);
	res = ft_complex_abs(z);
	if (res < 59.39 || res > 59.41)
		return (3);
	return (0);
}

int	test_ft_complex_addl(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_addl(x, 42);
	if (res.real != 84 || res.imaginary != 42)
		return (1);
	res = ft_complex_addl(y, 42);
	if (res.real != 42 || res.imaginary != 84)
		return (1);
	return (0);
}

int	test_ft_complex_mull(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_mull(x, 2);
	if (res.real != 84 || res.imaginary != 0)
		return (1);
	res = ft_complex_mull(y, 2);
	if (res.real != 0 || res.imaginary != 84)
		return (1);
	return (0);
}

int	test_ft_complex_muld(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_muld(x, 2.5);
	if (res.real != 105 || res.imaginary != 0)
		return (1);
	res = ft_complex_muld(y, 2.5);
	if (res.real != 0 || res.imaginary != 105)
		return (1);
	return (0);
}
