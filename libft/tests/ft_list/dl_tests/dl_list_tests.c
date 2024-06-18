/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2024/05/30 12:10:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/dl_tests.h"

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"add_front", t_dladd_front}, {"add_back", \
		t_dladd_back}, {"apply", t_dlapply}, {\
		"apply_range", t_dlapply_range}, {\
		"apply_range_node", t_dlapply_range_node}, {\
		"clear", t_dlclear}, {"clear_range", \
		t_dlclear_range}, {"create", t_dlcreate}, {\
		"copy_node", t_dlcopy_node}, {"copy_list", \
		t_dlcopy_list}, {"delete_self", \
		t_dl_delete_self}, {"delete_range", \
		t_dldelete_range}, {"delete", t_dldelete}, \
		{"find", t_dlfind}, {"get_datas", \
		t_dlget_datas}, {"get_nodes", t_dlget_nodes}, \
		{"at", t_dl_at}, {"begin", \
		t_dl_begin}, {"end", t_dl_end}, {\
		"map", t_dl_map}, {"new", t_dl_new}, \
		{"pop", t_dl_pop}, {"pop_back", \
		t_dl_pop_back}, {"push", t_dl_push}, \
		{"push_back", t_dl_push_back}, {"rev", \
		t_dl_rev}, {"size", t_dl_size}, {\
		"size_of_data", t_dl_size_of_data}, {\
		"subrange", t_dl_subrange}, {NULL, NULL}};

	return (var);
}

int	tests_doubly_linked_list_all(void)
{
	int				collect;
	const t_test	*test = init_tests();

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
