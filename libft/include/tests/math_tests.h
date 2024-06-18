/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:17:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/27 02:13:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_TESTS_H
# define MATH_TESTS_H

/* @file: tests/ft_math/tests_complex.c */
int	test_ft_complex_abs(void);
int	test_ft_complex_add(void);
int	test_ft_complex_addl(void);
int	test_ft_complex_mull(void);
int	test_ft_complex_muld(void);

/* @file: tests/ft_math/tests_log.c */
int	test_ft_log(void);
int	test_ft_llogof(void);
int	test_ft_ullogof(void);
int	test_ft_logof(void);

/* @file: tests/ft_math/tests_intrange.c */
int	test_ft_range(void);
int	test_ft_range_f(void);
int	test_ft_range_d(void);

/* @file: tests/ft_math/tests_sqrt.c */
int	test_ft_sqrt(void);

/* @file: tests/ft_math/tests_minmax.c */
int	test_ft_min(void);
int	test_ft_max(void);

/* @file: tests/ft_math/tests_pow.c */
int	test_ft_pow(void);

/* @file: tests/ft_math/tests_round.c */
int	test_ft_round(void);

/* @file: tests/ft_math/tests_clamp.c */
int	test_ft_clamp(void);
int	test_ft_clamp_f(void);
int	test_ft_clamp_d(void);

/* @file: tests/ft_math/tests_abs.c */
int	test_ft_abs(void);

#endif
