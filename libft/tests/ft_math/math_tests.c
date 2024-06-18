/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:16:35 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:24:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/math_tests.h"

int	tests_math(void)
{
	int				i;
	const t_test	tests[] = {
	{"abs", test_ft_abs}, {"clamp", test_ft_clamp},
	{"complex_abs", test_ft_complex_abs},
	{"complex_addl", test_ft_complex_addl},
	{"complex_mull", test_ft_complex_mull},
	{"complex_muld", test_ft_complex_muld},
	{"range", test_ft_range}, {"range_f", test_ft_range_f},
	{"range_d", test_ft_range_d}, {"log", test_ft_log},
	{"llogof", test_ft_llogof}, {"ullogof", test_ft_ullogof},
	{"logof", test_ft_logof}, {"min", test_ft_min},
	{"max", test_ft_max}, {"pow", test_ft_pow}, {"round", test_ft_round},
	{"sqrt", test_ft_sqrt}, {"clamp_f", test_ft_clamp_f},
	{"clamp_d", test_ft_clamp_d}, {NULL, NULL}};

	i = 0;
	run_test(tests, &i);
	return (i);
}
