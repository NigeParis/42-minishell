/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:27:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string.h"

#define MAGIC 42

int	eval_base(int *t_cases, const char *bases, const char *expected_results[])
{
	char	*res;
	size_t	j;

	j = 0;
	while (t_cases[j] != MAGIC)
	{
		res = ft_itoa_base(t_cases[j], bases);
		if (ft_strcmp(res, expected_results[j]) != 0)
			return (free(res), j + 1);
		free(res);
		j++;
	}
	return (0);
}

int	check_base_error(void)
{
	if (ft_itoa_base(0, "0") != NULL || ft_itoa_base(0, "010") != NULL || \
	ft_itoa_base(0, "0123456789+") != NULL || ft_itoa_base(0, "0123456789a-") \
	!= NULL || ft_itoa_base(0, "0123456789a1") != NULL || \
	ft_itoa_base(0, "0123456789a ") != NULL || ft_itoa_base(0, "0123456789\t") \
	!= NULL)
		return (15);
	return (0);
}

int	test_itoa_base(void)
{
	size_t		j;
	const int	t_cases[] = {0, 123, -456, 7890, -12345, MAGIC};
	const char	*bases[] = {"0123456789abcdef", "0123456789", "01",
		"0123456789ABCDEF"};
	const char	*expected_results[sizeof(bases)
		/ sizeof(bases[0])][sizeof(t_cases) / sizeof(t_cases[0])] = {{"0", "7b",
		"-1c8", "1ed2", "-3039"}, {"0", "123", "-456", "7890", "-12345"}, {"0",
		"1111011", "-111001000", "1111011010010", "-11000000111001"}, {"0",
		"7B", "-1C8", "1ED2", "-3039"}};

	j = 0;
	while (j < sizeof(bases) / sizeof(bases[0]))
	{
		if (eval_base((int *)t_cases, bases[j], expected_results[j]) != 0)
			return (j + 1);
		j++;
	}
	if (check_base_error() != 0)
		return (j + check_base_error());
	return (0);
}
