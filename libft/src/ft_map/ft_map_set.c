/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:18:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_vector.h"

#include <stdio.h>
#include <stdlib.h>

static void	setup_map_node(t_map_node *map_node, const void *key,
		const void *value)
{
	map_node->data = (void *)value;
	map_node->key = key;
	map_node->hash = 0;
}

bool	ft_map_set(t_map *map, const void *key, const void *value, size_t size)
{
	t_map_node	*map_node;
	t_list		*reuse_node;

	map_node = ft_map_get_node(map, key, size);
	reuse_node = NULL;
	if (map_node)
		return (map_node->data = (void *)value, true);
	if (map->reserved_nodes->count)
		reuse_node = ft_vec_pop(map->reserved_nodes);
	else
		map_node = malloc(sizeof(t_map_node));
	if (!map_node && !reuse_node)
		return (false);
	if (reuse_node)
		map_node = reuse_node->data;
	else
		reuse_node = ft_ll_create(map_node);
	setup_map_node(map_node, key, value);
	map_node->hash = map->hash(key, size);
	ft_ll_add_front(&map->nodes[map_node->hash % map->capacity], reuse_node);
	map->weights[map_node->hash % map->capacity]++;
	map->w_total++;
	return (true);
}

void	ft_map_set_cmp(t_map *map, t_data_cmp cmp)
{
	map->cmp = cmp;
}

void	ft_map_set_hash(t_map *map, t_memhash hash)
{
	map->hash = hash;
}
