/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:02:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:33:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/args_tests.h"

int	parse_args_test(void)
{
	return (0);
}

int	tests_args(void)
{
	int				collect;
	const t_test	test[] = {
	{"getset_version", getset_version_test}, {"getset_progname", \
		getset_program_name_test}, {"getset_opt_list", getset_opt_list_test},
	{"parse_args", parse_args_test}, {"setup_prog", tests_setup_prog},
	{"getset_custom_parser", getset_custom_checker_test}, {NULL, NULL}};

	collect = 0;
	run_test(test, &collect);
	return (collect);
}
