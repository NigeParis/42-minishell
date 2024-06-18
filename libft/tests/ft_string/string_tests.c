/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 14:25:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

int		t_string_tests(void);
int		mem_tests(void);
int		str_tests(void);
int		char_tests(void);

static const t_test	*load_submodules_tests(void)
{
	static const t_test	tests[] = {
	{"mem", mem_tests},
	{"str", str_tests},
	{"char", char_tests},
	{"t_string", t_string_tests},
	{NULL, NULL}
	};

	return (tests);
}

int	tests_string(void)
{
	size_t			i;
	int				collect;
	int				prev;
	const t_test	*tests = load_submodules_tests();

	i = 0;
	collect = 0;
	while (tests[i].name != NULL)
	{
		prev = collect;
		ft_putendl_fd("\nTesting::", STDOUT_FILENO);
		ft_putendl_fd(tests[i].name, STDOUT_FILENO);
		collect += tests[i++].test();
		ft_putstr_fd("\nTesting sub-module ", STDOUT_FILENO);
		ft_putstr_fd(tests[i - 1].name, STDOUT_FILENO);
		if (prev != collect)
			ft_putendl_fd(" \033[31mKO\033[0m", STDOUT_FILENO);
		else
			ft_putendl_fd(" \033[32mOK\033[0m", STDOUT_FILENO);
	}
	return (collect);
}
