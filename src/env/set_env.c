/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:08 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 15:13:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include "pair.h"
#include <stdlib.h>

static int	local_pair_cmp(const void *a, const void *b)
{
	if (!a || !b)
		return (-1);
	return (ft_strcmp(((const t_pair *)a)->first, (const char *)b));
}

int	set_env(t_vector **env, char *keyname, char *value)
{
	t_pair	*pair;
	char	*left;
	char	*right;

	pair = (t_pair *)ft_vec_get(*env, keyname, &local_pair_cmp);
	if (pair)
	{
		free(pair->second);
		pair->second = ft_strdup(value);
		return (EXIT_SUCCESS);
	}
	left = ft_strdup(keyname);
	if (!left)
		return (EXIT_FAILURE);
	right = ft_strdup(value);
	if (!right)
		return (free(left), EXIT_FAILURE);
	pair = new_pair(left, right);
	if (!pair)
		return (free(left), free(right), EXIT_FAILURE);
	if (ft_vec_add(env, pair) == false)
		return (destroy_pair_deep(pair), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
