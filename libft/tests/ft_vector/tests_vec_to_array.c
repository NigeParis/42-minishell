/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:35:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:41:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

int	test_vec_to_array(void)
{
	t_vector	*vector;
	const char	**array;

	vector = ft_vec_new();
	ft_vec_add(&vector, "Hello");
	ft_vec_add(&vector, "world");
	ft_vec_add(&vector, "this");
	ft_vec_add(&vector, "is");
	ft_vec_add(&vector, "Zod");
	array = (const char **)ft_vec_to_array(&vector);
	if (ft_strcmp(array[0], "Hello") != 0)
		return (1);
	if (ft_strcmp(array[1], "world") != 0)
		return (1);
	if (ft_strcmp(array[2], "this") != 0)
		return (1);
	if (ft_strcmp(array[3], "is") != 0)
		return (1);
	if (ft_strcmp(array[4], "Zod") != 0)
		return (1);
	free(array);
	return (0);
}
