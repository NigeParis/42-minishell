/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 16:18:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map_node	*ft_map_get(t_map *map, const void *key, size_t size)
{
	size_t		index;
	t_list		*node;
	t_map_node	*map_node;

	index = map->hash(key, map->capacity, size);
	node = &map->nodes[index];
	while (node && node->data)
	{
		map_node = (t_map_node *)node->data;
		if (map_node->used && !map->cmp(map_node->key, key))
			return (map_node);
		node = node->next;
	}
	return (NULL);
}

size_t	ft_map_size(const t_map *map)
{
	return (map->size);
}

size_t	ft_map_capacity(const t_map *map)
{
	return (map->capacity);
}
