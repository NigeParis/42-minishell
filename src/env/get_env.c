/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 15:07:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include "ft_vector_types.h"
#include "ft_string.h"
#include "ft_addons.h"

static int	local_pair_cmp(const void *a, const void *b)
{
	return (ft_strcmp(((const t_pair *)a)->first, (const char *)b));
}

char	*get_env(t_vector *env, char *keyname)
{
	const t_pair	*pair;

	pair = (const t_pair *)ft_vector_get(env, keyname, &local_pair_cmp);
	if (pair)
		return (pair->second);
	return (NULL);
}
