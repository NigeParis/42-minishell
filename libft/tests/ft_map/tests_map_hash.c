/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:21:33 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:24:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_map.h"
#include "ft_string.h"

// we dont really test the hash function, we just test that
// it doesn't overflow our map

int	test_map_hash(void)
{
	size_t	ret;
	size_t	ret2;

	ret = ft_hash_djb2("key", ft_strlen("key"));
	ret2 = ft_hash_djb2("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_sdbm("key", ft_strlen("key"));
	ret2 = ft_hash_sdbm("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_fnv1a("key", ft_strlen("key"));
	ret2 = ft_hash_fnv1a("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_dummy("key", ft_strlen("key"));
	ret2 = ft_hash_dummy("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	return (0);
}
