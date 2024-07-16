/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:22:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"

#include <stdlib.h>

int	test_map_remove(void)
{
	char	*str;
	void	*ret;
	t_map	*map;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_remove(map, "key", ft_strlen("key"));
	if (ret == NULL)
		return (1);
	else if (ret != str)
		return (2);
	ret = ft_map_remove(map, "key2", ft_strlen("key2"));
	if (ret != NULL)
		return (3);
	ft_map_destroy(map);
	free(str);
	return (0);
}
