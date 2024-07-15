/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 13:35:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell_types.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	create_base_env(t_minishell_control *ctrl)
{
	const char	*b_env[] = {"PATH=/usr/bin/", NULL};

	return (create_env(ctrl, (const char **)&b_env));
}

int	create_env(t_minishell_control *ctrl, const char **envp)
{
	size_t	i;
	t_pair	*pair;

	i = 0;
	ctrl->env = ft_vec_from_size(ft_len_2d((const void **)envp));
	if (ctrl->env == NULL)
		return (EXIT_FAILURE);
	while (envp[i])
	{
		pair = malloc(sizeof(t_pair));
		if (pair == NULL)
			return (EXIT_FAILURE);
		pair->first = ft_strdup(envp[i]);
		if (pair->first == NULL)
			return (EXIT_FAILURE);
		((char *)pair->first)[ft_strchr(envp[i], '=') - envp[i]] = '\0';
		pair->second = ft_strdup(ft_strchr(envp[i], '=') + 1);
		if (pair->second == NULL || ft_vec_add(&ctrl->env, pair) == false)
			return (EXIT_FAILURE);
		i++;
	}
	if (!i)
		return (create_base_env(ctrl));
	return (EXIT_SUCCESS);
}

int	setup_minishell(t_minishell_control *minishell, int ac, char **arg, \
					char **envp)
{
	stifle_history(10);
	ft_setup_prog((const char *const *)arg);
	ft_bzero(minishell, sizeof(t_minishell_control));
	minishell->shoulcontinue = true;
	if (create_env(minishell, (const char **)envp) == EXIT_FAILURE)
		return (minishell->exit = 1, EXIT_FAILURE);
	if (minishell_parser_init(minishell) == EXIT_FAILURE)
		return (minishell->exit = 1, EXIT_FAILURE);
	signal_init();
	return (EXIT_SUCCESS);
}
