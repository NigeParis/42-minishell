/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:08:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 16:00:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_atof(void)
{
	double			res;
	size_t			i;
	const float		marge = 0.00001;
	const double	t_cases[] = {
		1.13, 3.14, 0.0, 0.1, 0.0001, -0.2, -0.3, 0.3, 1200, 0,
		3.15, -3.15, 0.15
	};
	const char		*t_str[] = {
		"1.13", "3.14", "0.0", "0.1", "0.0001",
		"-0.2", "-.3", ".3", "1200", "0", "  +3.15",
		"  -3.15", "  .15"
	};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_atof(t_str[i]);
		if (res < t_cases[i] - marge || res > t_cases[i] + marge)
			return (i + 1);
		i++;
	}
	return (0);
}
