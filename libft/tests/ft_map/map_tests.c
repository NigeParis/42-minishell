/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:09:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/map_tests.h"

// see with --leak-check=full
int	tests_map(void)
{
	int				collect;
	const t_test	test[] = {
	{"create", test_map_create},
	{"destroy", test_map_destroy}, // here
	{"destroy_free", test_map_destroy_free},
	{"clear", test_map_clear}, // here
	{"set", test_map_set},
	{"set_cmp", test_map_set_cmp},
	{"set_hash", test_map_set_hash},
	{"get", test_map_get},
	{"size", test_map_size},
	{"capacity", test_map_capacity},
	{"remove", test_map_remove}, // here
	{"hash", test_map_hash},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
