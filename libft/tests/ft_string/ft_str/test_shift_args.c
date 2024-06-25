/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shift_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:41:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_shift_args(void)
{
	const char	**test;
	int			fake_argc;
	const char	*ret;
	const char	*fake_args[] = (const char *[]) \
	{"test", "1", "2", "3", "4", NULL};

	test = fake_args;
	ret = NULL;
	fake_argc = 5;
	ret = ft_shift_args(&test, &fake_argc);
	if (fake_argc != 4 || ft_strcmp(test[0], "1") != 0 || \
	ft_strcmp(test[1], "2") != 0 || ft_strcmp(test[2], "3") != 0 || \
	ft_strcmp(test[3], "4") != 0 || ft_strcmp(ret, "test") != 0)
		return (1);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	ret = ft_shift_args(&test, &fake_argc);
	if (fake_argc != 0 || ret != NULL)
		return (2);
	return (0);
}
