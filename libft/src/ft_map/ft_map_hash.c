/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:07:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 23:09:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

// Default hash function provided by map
// Overflows are possible

// Default hash function for ft_map
// Very fast, but not very good
// see http://www.cse.yorku.ca/~oz/hash.html
// See ft_hash_sdbm or ft_hash_fnv1a for less collisions prone hash functions
size_t	ft_hash_djb2(const void *key, size_t size)
{
	unsigned char	*str;
	size_t			hash;

	hash = 5381;
	str = (unsigned char *)key;
	while (size--)
		hash = (hash << 5) + hash + *str++;
	return (hash);
}

// Better hash function
// Slower, but better
// see http://www.cse.yorku.ca/~oz/hash.html
// overal better than djb2 but default hash function stays djb2 because it's
// faster and easier to understand, plus it's not that bad... right ?
size_t	ft_hash_sdbm(const void *key, size_t size)
{
	unsigned char	*str;
	size_t			hash;

	hash = 0;
	str = (unsigned char *)key;
	while (size--)
		hash = *str++ + (hash << 6) + (hash << 16) - hash;
	return (hash);
}

// Another hash function
// Slower, but better
// see
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
//
// 64 bits version check is just that the size of size_t impact the starting
// hash value to lower the number of collisions otherwise we use the 32 bits
// version.
// lets hope that 128 bits computers will not be a thing...
//
// note: djb2 and sdbm are 32 bits hash functions and are not impacted by
// the size of size_t
size_t	ft_hash_fnv1a(const void *key, size_t size)
{
	unsigned char	*str;
	size_t			hash;

	if (sizeof(size_t) == 8)
		hash = 0xcbf29ce484222325;
	else
		hash = 0x811c9dc5;
	str = (unsigned char *)key;
	while (size--)
		hash = (*str++ ^ hash) * 0x01000193;
	return (hash);
}

// dumbest hash function ever
// just for testing purposes when you don't care about collisions
// or when you want to test your map with a hash function that doesn't
// overflow at all ever
//
size_t	ft_hash_dummy(const void *key, size_t size)
{
	unsigned char	*str;
	size_t			hash;

	str = (unsigned char *)key;
	hash = 0;
	while (size--)
		hash += *str++;
	return (hash);
}
