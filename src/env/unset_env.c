/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:20:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:03:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "pair.h"

static int	loc_pair_cmpfirst(void *a, void *b)
{
	if (!a || !b)
		return (-1);
	return (ft_strcmp(a, b));
}

// We cant use ft_vec_get as we need the index of the occurence to call 
// ft_vec_remove. Sadge
// We could use pair_fcmp_first directly with ft_strcmp but we would need to 
// do an ugly cast to pass ft_strcmp to bool return.
// (still, would works tho but ugly)
//
// maybe add a ft_vecspn that would return the index of the first occurence?

bool	unset_env(t_vector *env, const char *key)
{
	size_t	i;
	t_pair	*pair;
	t_pair	key_pair;

	i = 0;
	key_pair.first = (char *)key;
	key_pair.second = NULL;
	pair = NULL;
	while (i < env->count)
	{
		pair = ft_vec_at(env, i);
		if (pair && pair_fcmpfirst(pair, &key_pair, loc_pair_cmpfirst) == 0)
			break ;
		i++;
	}
	if (!pair)
		return (false);
	ft_vec_remove(env, i, (t_data_apply)destroy_pair_deep);
	return (true);
}
