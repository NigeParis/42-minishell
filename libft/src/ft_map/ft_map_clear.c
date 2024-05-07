/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:29:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 17:49:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_list.h"

static void	clear_node(void *data)
{
	t_map_node	*map_node;

	if (!data)
		return ;
	map_node = (t_map_node *)data;
	map_node->used = false;
}

void	ft_map_clear(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
		ft_listapply(&map->nodes[i++], clear_node);
	map->size = 0;
}
