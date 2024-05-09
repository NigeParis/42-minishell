/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 23:27:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"

void	ft_map_remove(t_map *map, const void *key, size_t size)
{
	size_t		index;
	t_list		*node;
	t_map_node	*map_node;

	index = map->hash(key, map->capacity, size);
	node = &map->nodes[index];
	map_node = (t_map_node *)node->data;
	while (node)
	{
		if (((t_map_node *)node->data)->used && 
		!map->cmp(((t_map_node *)node->data)->key, key))
			break ;
		node = node->next;
	}
	if (node && map_node->used)
	{
		map_node->used = false;
		map->size--;
	}
}
