/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 11:53:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_map.h"
#include "ft_vector.h"
#include <stdlib.h>

static t_data_apply	singleton_custom_destroy(const t_data_apply custom_destroy)
{
	static t_data_apply	f_ptr = NULL;

	if (custom_destroy)
		f_ptr = custom_destroy;
	return (f_ptr);
}

static void	wrapper_destroy(void *restrict data)
{
	t_data_apply	destroy;
	t_map_node		*map_node;

	destroy = singleton_custom_destroy(NULL);
	map_node = (t_map_node *)data;
	if (destroy)
		(*destroy)(map_node->data);
	free(map_node);
}

void	ft_map_destroy(t_map *map)
{
	ft_map_destroy_free(map, NULL);
}

static void	rsv_del(void *data)
{
	t_list	*node;

	node = (t_list *)data;
	if (node && node->data)
		wrapper_destroy(node->data);
	free(node);
}

void	ft_map_destroy_free(t_map *map, t_data_apply free_fun)
{
	size_t	i;

	singleton_custom_destroy(free_fun);
	i = 0;
	while (i < map->capacity)
	{
		ft_ll_clear(&map->nodes[i++], wrapper_destroy);
	}
	free(map->nodes);
	free(map->weights);
	ft_vec_apply(map->reserved_nodes, rsv_del);
	ft_vec_destroy(&map->reserved_nodes);
	free(map);
}
