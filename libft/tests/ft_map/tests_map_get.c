/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:14:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:25:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	---
	// search for a non existing key in a full map
	map = ft_map_create(1);
*/

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"

#include <stdlib.h>

int	test_map_get(void)
{
	char		*str;
	t_map		*map;
	void		*ret;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (ret == NULL)
		return (1);
	else if (ft_strcmp((char *)ret, "value"))
		return (2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (ret != NULL)
		return (3);
	ft_map_destroy(map);
	free(str);
	return (0);
}
