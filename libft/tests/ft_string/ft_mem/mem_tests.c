/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 20:54:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/str__mem_tests.h"

int	mem_tests(void)
{
	int				collect;
	const t_test	tests[] = {
	{"apply_2d", test_apply_2d}, {"free_2d", test_free_2d},
	{"len_2d", test_len_2d}, {"fd_to_buff", test_fd_to_buff},
	{"bzero", test_bzero}, {"calloc", test_calloc}, {"realloc", test_realloc},
	{"free", test_free}, {"memchr", test_memchr}, {"memcmp", test_memcmp},
	{"memcpy", test_memcpy}, {"memmap", test_memmap}, {"memmove", test_memmove},
	{"memset", test_memset}, {"swap", test_swap}, {"qsort", test_qsort},
	{NULL, NULL}
	};

	collect = 0;
	run_test(tests, &collect);
	return (collect);
}
