/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:23:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:24:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_H
# define MAP_TESTS_H

// File: tests/ft_map/tests_map_cappacity.c
int	test_map_capacity(void);

// File: tests/ft_map/tests_map_clear.c
int	test_map_clear(void);

// File: tests/ft_map/tests_map_create.c
int	test_map_create(void);

// File: tests/ft_map/tests_map_destroy.c
int	test_map_destroy(void);
int	test_map_destroy_free(void);

// File: tests/ft_map/tests_map_get.c
int	test_map_get(void);

// File: tests/ft_map/tests_map_hash.c
int	test_map_hash(void);

// File: tests/ft_map/tests_map_remove.c
int	test_map_remove(void);

// File: tests/ft_map/tests_map_set.c
int	test_map_set(void);

// File: tests/ft_map/tests_map_set_cmphash.c
int	test_map_set_cmp(void);
int	test_map_set_hash(void);

// File: tests/ft_map/tests_map_size.c
int	test_map_size(void);

#endif /* MAP_TESTS_H */
