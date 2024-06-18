/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:11:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/ll_tests.h"

int	tests_linked_list_all(void)
{
	int				collect;
	const t_test	test[] = {
	{"add_front", t_ll_add_front}, {"add_back",
		t_ll_add_back},	{"apply", t_ll_apply},	{
		"apply_range", t_ll_apply_range}, {
		"apply_range_node", t_ll_apply_range_node}, {
		"clear", t_ll_clear}, {"create",
		t_ll_create}, {"copy_node", t_ll_copy_node},
	{"copy_list", t_ll_copy_list},	{"delone",
		t_ll_delone}, {"delete_range", t_ll_delete_range},
	{"find", t_ll_find}, {"get_datas",
		t_ll_get_datas}, {"get_nodes", t_ll_get_nodes}, {
		"end", t_ll_end}, {"at", t_ll_at}, {
		"map", t_ll_map}, {"new", t_ll_new}, {
		"push", t_ll_push}, {"push_back",
		t_ll_push_back}, {"pop", t_ll_pop}, {
		"pop_back", t_ll_pop_back}, {"rev", t_ll_rev},
	{"size", t_ll_size}, {"size_match",
		t_ll_size_match}, {"subrange", t_ll_subrange},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
