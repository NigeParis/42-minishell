/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 11:56:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_vector.h"
#include "ft_list_types.h"

#include <stdio.h>

void	*ft_map_remove(t_map *map, const void *key, size_t size)
{
	size_t		hash;
	t_list		*prev;
	t_list		*cur;

	hash = map->hash(key, size) % map->capacity;
	prev = NULL;
	cur = map->nodes[hash];
	while (cur)
	{
		if (map->cmp(((t_map_node *)cur->data)->key, key) == 0)
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (NULL);
	if (!prev)
		map->nodes[hash] = cur->next;
	else
		prev->next = cur->next;
	cur->next = NULL;
	ft_vec_add(&map->reserved_nodes, cur);
	map->weights[hash]--;
	map->w_total--;
	return (((t_map_node *)cur->data)->data);
}
