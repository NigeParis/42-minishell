/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 11:55:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "ft_defs.h"
# include "ft_map_types.h"

/* ************************************************************************** */
/*                          MAP FUNCTIONS                                     */
/* ************************************************************************** */

/// @brief Create a new map
/// @param capacity possible number of elements in the map
/// @return a pointer to the new map
/// @file ft_map/ft_map_create.c
t_map		*ft_map_create(size_t capacity);

/// @brief Destroy a map and free the nodes
/// @param map map to destroy
/// @file ft_map/ft_map_destroy.c
/// @return void
void		ft_map_destroy(t_map *map);

/// @brief Destroy a map and free the nodes and the user data in them using a
/// function passed as an argument
/// @param map map to destroy
/// @param free_data function to free the data in the map
/// @file ft_map/ft_map_destroy.c
/// @return void
void		ft_map_destroy_free(t_map *map, t_data_apply free_data);

/// @brief Clears a map
/// @param map map to clear
/// @file ft_map/ft_map_clear.c
/// @return void
void		ft_map_clear(t_map *map);

/// @brief Set a value in a map
/// @param map map to set the value in
/// @param key key of the value
/// @param value value to set
/// @param size size of the key
/// @file ft_map/ft_map_set.c
/// @return true if the value was set, otherwise if key creation failed false
bool		ft_map_set(t_map *map, const void *key, const void *value,
				size_t size);

/// @brief Set the compare function of a map
/// @param map map to set the compare function
/// @param cmp compare function newly set
/// @file ft_map/ft_map_set.c
/// @return void
void		ft_map_set_cmp(t_map *map, t_data_cmp cmp);

/// @brief Set the hash function of a map
/// @param map map to set the hash function
/// @param hash hash function newly set
/// @file ft_map/ft_map_set.c
/// @return void
void		ft_map_set_hash(t_map *map, t_memhash hash);

/// @brief Get a node from a map
/// @param map map to get the node from
/// @param key key of the node
/// @param size size of the key
/// @file ft_map/ft_map_get.c
t_map_node	*ft_map_get_node(t_map *map, const void *key, size_t size);

/// @brief Get a value from a map
/// @param map map to get the value from
/// @param key key of the value
/// @param key_size size of the key
/// @file ft_map/ft_map_get.c
/// @return a pointer to the user data or NULL if the key is not found
void		*ft_map_get(t_map *map, const void *key, size_t key_size);

/// @brief Get the number of elements in a map
/// @param map map to get the size from
/// @file ft_map/ft_map_size.c
/// @return the number of elements in the map
size_t		ft_map_size(const t_map *map);

/// @brief Get the capacity of a map
/// @param map map to get the capacity from
/// @file ft_map/ft_map_get.c
/// @return the capacity of the map
size_t		ft_map_capacity(const t_map *map);

/// @brief Remove a value from a map
/// @param map map to remove the value from
/// @param key key of the value
/// @param size size of the key
/// @file ft_map/ft_map_remove.c
/// @return the value removed or NULL if the key is not found
void		*ft_map_remove(t_map *map, const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @file ft_map/ft_map_hash.c
/// @return the hash of the key
size_t		ft_hash_djb2(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @file ft_map/ft_map_hash.c
/// @return the hash of the key
size_t		ft_hash_sdbm(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @return the hash of the key
size_t		ft_hash_fnv1a(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @file ft_map/ft_map_hash.c
/// @return the hash of the key
/// @note this hash function is not very good, full of collisions
/// but it's very fast, easy to understand and never overflows.
/// use it ONLY for TESTing purposes
size_t		ft_hash_dummy(const void *key, size_t size);

#endif /* FT_MAP_H */
