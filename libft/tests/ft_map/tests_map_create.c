/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:07:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:07:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"

int	test_map_create(void)
{
	t_map	*map;

	map = ft_map_create(10);
	if (map == NULL)
		return (1);
	ft_map_destroy(map);
	return (0);
}
