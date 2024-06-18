/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 13:53:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/vector_tests.h"

int	tests_vector(void)
{
	int				collect;
	const t_test	tests[] = {
	{"add", test_vec_add}, {"apply", test_vec_apply}, {"at", test_vec_at}, \
	{"cat", test_vec_cat}, {"clear", test_vec_clear}, \
	{"destroy", test_vec_destroy}, {"filter", test_vec_filter}, \
	{"map", test_vec_map}, {"new", test_vec_new}, {"pop", test_vec_pop}, \
	{"from_size", test_vec_from_size}, {"from_array", test_vec_from_array}, \
	{"convert_alloc_array", test_vec_convert_alloc_array}, \
	{"remove", test_vec_remove}, {"remove_if", test_vec_remove_if}, \
	{"reserve", test_vec_reserve}, {"reverse", test_vec_reverse}, \
	{"shift", test_vec_shift}, {"sort", test_vec_sort}, \
	{"shrink", test_vec_shrink}, {"swap", test_vec_swap}, \
	{"get", test_vec_get}, {"to_array", test_vec_to_array}, \
	{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
