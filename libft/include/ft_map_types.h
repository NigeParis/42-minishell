/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:02:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:47:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_TYPES_H
# define FT_MAP_TYPES_H

# include "ft_list_types.h"
# include "ft_defs.h"
# include "ft_vector_types.h"
# include <stdbool.h>
# include <stddef.h>

/// @brief Structure representing a node in a map
/// @param data The data of the node
/// @param key The key of the node
/// @param used Whether the node is used or not
typedef struct s_map_node
{
	void		*data;
	const void	*key;
	size_t		hash;
}				t_map_node;

typedef size_t		(*t_memhash)(const void *data, size_t data_len);

/// @brief Structure representing a map
/// @param capacity The capacity of the map
/// @param size The size of the map
/// @param nodes The nodes of the map (array of lists distributed by hash)
/// @param cmp The compare function of the map
/// @param hash The hash function of the map
/// @code
/// #include "ft_map.h"
/// #include "ft_string.h"
/// #include <stdio.h>
///
/// static void goodbye(void *data)
/// {
///	printf("Goodbye %s\n", (char *)data);
///	free(data);
/// }
///
/// int main()
/// {
///	t_map *map;
///	char *key = "key";
///	char *value = ft_strdup("value");
///	char *ptr;
///
///	map = ft_map_create(5);
///
///	ft_map_set(map, key, value, ft_strlen(key));
///	ft_map_set(map, "key2", ft_strdup("val32"), ft_strlen("key2"));
///
///	ptr = ft_map_remove(map, "key2", ft_strlen("key2"));
///	goodbye(ptr);
///
///	ft_map_set(map, "key3", ft_strdup("val3"), ft_strlen("key3"));
///
///	printf("---\n");
///	ft_map_destroy_free(map, goodbye);
///	return (0);
/// }
/// @endcode
/// @see ft_map_create
typedef struct s_map
{
	size_t		capacity;
	size_t		*weights;
	size_t		w_total;
	t_list		**nodes;
	t_data_cmp	cmp;
	t_memhash	hash;
	t_vector	*reserved_nodes;
}				t_map;

#endif /* FT_MAP_TYPES_H */
