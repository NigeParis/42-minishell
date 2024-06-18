/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:07:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_string.h"
#include "ft_map_types.h"
#include <stdlib.h>

// check valgrind for no memory leak
int	test_map_destroy(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy(map);
	return (0);
}

// accessing to key[0] and value[0] after the call to check
// that no free occured on the data at first call
int	test_map_destroy_free(void)
{
	t_map	*map;
	char	*key;
	char	*value;

	key = ft_strdup("keys");
	value = ft_strdup("values");
	map = ft_map_create(10);
	ft_map_set(map, key, value, ft_strlen(key));
	ft_map_destroy_free(map, NULL);
	key[0] = 'k';
	value[0] = 'v';
	map = ft_map_create(15);
	ft_map_set(map, key, value, ft_strlen(key));
	ft_map_destroy_free(map, free);
	free(key);
	return (0);
}
