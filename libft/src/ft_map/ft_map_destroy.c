/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 17:48:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_map.h"
#include <stdlib.h>

static t_data_apply	singleton_freedata_ptr(t_data_apply ptr)
{
	static t_data_apply	singleton = NULL;

	if (ptr)
		singleton = ptr;
	return (singleton);
}

static void	destroy_node(void *data)
{
	t_map_node		*map_node;
	t_data_apply	del;

	del = singleton_freedata_ptr(NULL);
	map_node = (t_map_node *)data;
	if (map_node && map_node->used && del)
		del(map_node);
}

void	ft_map_destroy(t_map *map)
{
	free(map->nodes);
	free(map);
}

void	ft_map_destroy_free(t_map *map, void (*free_data)(void *))
{
	size_t	i;

	i = 0;
	singleton_freedata_ptr(free_data);
	while (i < map->capacity)
	{
		ft_listapply(&map->nodes[i], destroy_node);
		i++;
	}
	ft_map_destroy(map);
}
