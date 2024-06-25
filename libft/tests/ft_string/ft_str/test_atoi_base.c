/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 16:42:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	test_base_resps(const char *base, const int *expected_results,
		const char **inputs)
{
	int	i;
	int	res;

	i = 0;
	while (inputs[i] != NULL)
	{
		res = ft_atoi_base(inputs[i], base);
		if (res != expected_results[i])
			return (i + 1);
		i++;
	}
	return (0);
}

static int	test_spaces(void)
{
	if (ft_atoi_base(" 0", "0123456789") != 0)
		return (1);
	if (ft_atoi_base(" 1", "0123456789") != 1)
		return (2);
	if (ft_atoi_base(" 9", "0123456789") != 9)
		return (3);
	if (ft_atoi_base(" 10", "0123456789") != 10)
		return (4);
	if (ft_atoi_base(" 99", "0123456789") != 99)
		return (5);
	if (ft_atoi_base(" -99", "0123456789") != -99)
		return (6);
	if (ft_atoi_base(" -0", "0123456789") != 0)
		return (7);
	if (ft_atoi_base(" -1", "0123456789") != -1)
		return (8);
	if (ft_atoi_base(" -10", "0123456789") != -10)
		return (9);
	if (ft_atoi_base(" -99", "0123456789") != -99)
		return (10);
	return (0);
}

static int	test_multi_sign(void)
{
	if (ft_atoi_base(" --99", "0123456789") != 99)
		return (1);
	if (ft_atoi_base(" -0", "0123456789") != 0)
		return (2);
	if (ft_atoi_base(" -++--1", "0123456789") != -1)
		return (3);
	if (ft_atoi_base(" -+--10", "0123456789") != -10)
		return (4);
	if (ft_atoi_base(" -+--99", "0123456789") != -99)
		return (5);
	return (0);
}

int	test_atoi_base(void)
{
	const char	*bases[] = {"0123456789", "01", "0123456789abcdef"};
	const int	expected_results[][11] = {
	{0, 1, 9, 10, 99, 0, -1, -9, -10, -99},
	{0, 1, 2, 3, 4, 0, -1, -2, -3, -4},
	{0, 10, 15, 16, 153, 0, -10, -15, -16, -153}
	};
	const char	*strs[][12] = {
	{"0", "1", "9", "10", "99", "0", "-1", "-9", "-10", "-99", NULL},
	{"0", "1", "10", "11", "100", "0", "-1", "-10", "-11", "-100", NULL},
	{"0", "a", "f", "10", "99", "0", "-a", "-f", "-10", "-99", NULL}
	};

	if (test_base_resps(bases[0], expected_results[0], strs[0]) || \
	test_base_resps(bases[1], expected_results[1], strs[1]) || \
	test_base_resps(bases[2], expected_results[2], strs[2]))
		return (1);
	if (ft_atoi_base("23", "011") || ft_atoi_base("23", "0") || \
	ft_atoi_base("23", "1") || ft_atoi_base("23", "0123456789-") || \
	ft_atoi_base("23", "0123456789+"))
		return (2);
	if (test_spaces())
		return (3);
	if (test_multi_sign())
		return (4);
	return (0);
}
