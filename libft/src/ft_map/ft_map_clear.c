/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:29:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 23:30:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_vector.h"

void	ft_map_clear(t_map *map)
{
	size_t	i;
	t_list	*cur;

	i = 0;
	while (i < map->capacity)
	{
		while (map->nodes[i])
		{
			cur = map->nodes[i];
			map->nodes[i] = map->nodes[i]->next;
			ft_vec_add(&map->reserved_nodes, cur);
		}
		map->weights[i] = 0;
		i++;
	}
	map->w_total = 0;
}
