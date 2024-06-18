/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:57:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:08:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/optional_test.h"
#include "tests/tests.h"

void	*add_4(void *val)
{
	long long	ptr;

	ptr = (long long)val;
	ptr += 4;
	return ((void *)ptr);
}

int	tests_optional(void)
{
	int				collect;
	const t_test	test[] = {
	{"copy", test_optional_copy},
	{"new", test_optional_new},
	{"from_val", test_optional_from_val},
	{"dup", test_optional_dup},
	{"chain", test_optional_chain},
	{"map", test_optional_map},
	{"unwrap", test_optional_unwrap},
	{"destroy", test_optional_destroy},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
