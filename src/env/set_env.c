/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:08 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/03 14:27:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include "pair.h"
#include <stdlib.h>

static int	local_pair_cmp(const void *a, const void *b)
{
	return (ft_strcmp(((const t_pair *)a)->first, (const char *)b));
}

void	set_env(t_vector **env, char *keyname, char *value)
{
	t_pair	*pair;

	pair = (t_pair *)ft_vec_get(*env, keyname, &local_pair_cmp);
	if (pair)
	{
		free(pair->second);
		pair->second = ft_strdup(value);
		return ;
	}
	pair = new_pair(keyname, value);
	ft_vec_add(env, pair);
}
