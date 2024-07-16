/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:17:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:39:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>

int	test_utoa(void)
{
	char				*res;
	size_t				i;
	const unsigned int	t_cases[] = {0, 123, 456, 7890, 12345};
	const char			*expected_results[] = \
	{"0", "123", "456", "7890", "12345"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_utoa(t_cases[i]);
		if (ft_strcmp(res, expected_results[i++]) != 0)
			return (i);
		free(res);
	}
	return (0);
}
