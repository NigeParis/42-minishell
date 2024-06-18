/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:11:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:41:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"

// clear the map and check if the value is still present
// try to double clear the map

int	test_map_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set(map, "key", "value", ft_strlen("key"));
	ft_map_clear(map);
	if (ft_map_get(map, "key", ft_strlen("key")) != NULL)
		return (1);
	ft_map_clear(map);
	ft_map_destroy(map);
	return (0);
}
