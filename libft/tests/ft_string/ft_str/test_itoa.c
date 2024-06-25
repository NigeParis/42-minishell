/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:26:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string.h"

int	test_itoa(void)
{
	char		*res;
	size_t		i;
	const int	t_cases[] = {0, 123, -456, 7890, -12345};
	const char	*expected_results[] = {"0", "123", "-456", "7890", "-12345"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_itoa(t_cases[i]);
		if (ft_strcmp(res, expected_results[i++]) != 0)
			return (i);
		free(res);
	}
	return (0);
}
