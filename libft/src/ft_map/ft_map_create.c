/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:11:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 23:12:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_string.h"
#include "ft_vector.h"

t_map	*ft_map_create(size_t size)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->capacity = size;
	map->w_total = 0;
	map->weights = ft_calloc(size, sizeof(size_t));
	if (!map->weights)
		return (free(map), NULL);
	map->nodes = ft_calloc(size, sizeof(t_list *));
	if (!map->nodes)
		return (free(map->weights), free(map), NULL);
	map->hash = &ft_hash_djb2;
	map->cmp = (int (*)(const void *, const void *)) & ft_strcmp;
	map->reserved_nodes = ft_vec_new();
	if (!map->reserved_nodes)
		return (free(map->weights), free(map->nodes), free(map), NULL);
	return (map);
}
