/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 17:46:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_map.h"
#include <stdlib.h>

static void setup_map_node(t_map_node *map_node, const void *key, const void *value)
{
	map_node->data = (void *)value;
	map_node->used = true;
	map_node->key = key;
}

int	ft_map_set(t_map *map, const void *key, const void *value, size_t size)
{
	size_t	index;
	t_list	*node;
	t_list	*prev;
	t_map_node	*map_node;

	index = map->hash(key, map->capacity, size);
	node = &map->nodes[index];
	while (node)
	{
		map_node = (t_map_node *)node->data;
		if (!map_node || !map->cmp(map_node->key, key))
			break ;
		prev = node;
		node = node->next;
	}
	if (node && map_node)
		return (setup_map_node(map_node, key, value), 0);
	map_node = malloc(sizeof(t_map_node));
	if (!map_node)
		return (1);
	if (!node)
		ft_listpush_back(&prev, map_node);
	else
		node->data = map_node;
	return (map->size++, setup_map_node(map_node, key, value), 0);
}

void	ft_map_set_cmp(t_map *map, int (*cmp)(const void *, const void *))
{
	map->cmp = cmp;
}

void	ft_map_set_hash(t_map *map, size_t (*hash)(const void *, size_t,
			size_t))
{
	map->hash = hash;
}
