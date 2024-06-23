/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:20:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 11:26:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "pair.h"

static int	loc_pair_cmpfirst(const void *a, const void *b)
{
	return (ft_strcmp((const char *)a, ((const t_pair *)b)->first));
}

bool	unset_env(t_vector *env, const char *key)
{
	size_t	i;
	t_pair	*pair;
	t_pair	key_pair;

	i = 0;
	key_pair.first = (char *)key;
	key_pair.second = NULL;
	while (i < env->count)
	{
		pair = ft_vec_get(env, key, loc_pair_cmpfirst);
		if (pair)
		{
			free(pair->first);
			free(pair->second);
			free(pair);
			ft_vec_remove(env, i, NULL);
			return (true);
		}
	}
	return (false);
}
