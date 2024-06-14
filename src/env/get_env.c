/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 17:21:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include "ft_vector_types.h"
#include "ft_vector.h"
#include "ft_string.h"

static int	local_pair_cmp(const void *a, const void *b)
{
	return (ft_strcmp(((const t_pair *)a)->first, (const char *)b));
}

char	*get_env(t_vector *env, char *keyname)
{
	const t_pair	*pair;

	pair = (const t_pair *)ft_vec_get(env, keyname, &local_pair_cmp);
	if (pair)
		return (pair->second);
	return (NULL);
}

char	**get_bourne_env(t_vector *env)
{
	char	**envp;
	char	*tmp;
	size_t	i;

	envp = (char **)malloc(sizeof(char *) * (env->count + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (i < env->count)
	{
		envp[i] = ft_strjoin(((t_pair *)env->datas[i])->first, "=");
		if (!envp[i])
			return (NULL);
		tmp = envp[i];
		envp[i] = ft_strjoin(envp[i], ((t_pair *)env->datas[i])->second);
		free(tmp);
		if (!envp[i])
			return (NULL);
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
