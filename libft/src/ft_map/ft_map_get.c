/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 11:54:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>

t_map_node	*ft_map_get_node(t_map *map, const void *key, size_t size)
{
	t_list		*bucket;
	t_map_node	*map_node;

	bucket = map->nodes[map->hash(key, size) % map->capacity];
	map_node = NULL;
	while (bucket)
	{
		map_node = bucket->data;
		if (map->cmp(map_node->key, key) == 0)
			break ;
		bucket = bucket->next;
	}
	if (map_node && map->cmp(map_node->key, key) == 0)
		return (map_node);
	return (NULL);
}

void	*ft_map_get(t_map *map, const void *key, size_t size)
{
	t_map_node	*map_node;

	map_node = ft_map_get_node(map, key, size);
	if (!map_node)
		return (NULL);
	return (map_node->data);
}

size_t	ft_map_size(const t_map *map)
{
	return (map->w_total);
}

size_t	ft_map_capacity(const t_map *map)
{
	return (map->capacity);
}
