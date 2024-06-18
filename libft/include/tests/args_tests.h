/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:33:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_TESTS_H
# define ARGS_TESTS_H

/* @file: tests/ft_args/args_tests.c */
int	parse_args_test(void);
int	tests_args(void);

/* @file: tests/ft_args/tests_custom_checker.c */
int	getset_custom_checker_test(void);

/* @file: tests/ft_args/tests_optlist.c */
int	getset_opt_list_test(void);

/* @file: tests/ft_args/tests_setup_prog.c */
int	tests_setup_prog(void);

/* @file: tests/ft_args/tests_version.c */
int	getset_version_test(void);

/* @file: tests/ft_args/tests_progname.c */
int	getset_program_name_test(void);

#endif /* ARGS_TESTS_H */
