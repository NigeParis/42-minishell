/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_test.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:08:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONAL_TEST_H
# define OPTIONAL_TEST_H

/* @file: tests/ft_optional/test_optional_new.c */
int		test_optional_new(void);

/* @file: tests/ft_optional/test_optional_dup.c */
int		test_optional_dup(void);

/* @file: tests/ft_optional/test_optional_copy.c */
int		test_optional_copy(void);

/* @file: tests/ft_optional/test_optional_unwrap.c */
int		test_optional_unwrap(void);

/* @file: tests/ft_optional/test_optional_from_val.c */
int		test_optional_from_val(void);

/* @file: tests/ft_optional/test_optional_chain.c */
int		test_optional_chain(void);

/* @file: tests/ft_optional/optional_tests.c */
void	*add_4(void *val);
int		tests_optional(void);

/* @file: tests/ft_optional/test_optional_map.c */
int		test_optional_map(void);

/* @file: tests/ft_optional/test_optional_destroy.c */
int		test_optional_destroy(void);

#endif /* INCLUDE/TESTS/OPTIONAL_TEST_H */
