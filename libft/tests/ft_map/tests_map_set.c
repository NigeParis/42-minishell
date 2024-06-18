/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:39:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"

int	test_map_set(void)
{
	char		*str;
	char		*str2;
	t_map		*map;

	str = ft_strdup("value");
	str2 = ft_strdup("value2");
	map = ft_map_create(1);
	if (ft_map_set(map, "key", str, ft_strlen("key")) != true)
		return (1);
	if (ft_map_set(map, "key", str2, ft_strlen("key")) != true)
		return (1);
	ft_map_destroy(map);
	free(str);
	free(str2);
	return (0);
}
