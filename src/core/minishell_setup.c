/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/20 18:57:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell_types.h"
#include "minishell.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	create_env(t_minishell_control *ctrl, const char **envp)
{
	size_t	i;
	t_pair	*pair;

	i = 0;
	ctrl->env = ft_vec_from_size(ft_len_2d((const void **)envp));
	while (envp[i])
	{
		pair = malloc(sizeof(t_pair));
		if (pair == NULL)
			return (EXIT_FAILURE);
		pair->first = ft_strdup(envp[i]);
		((char *)pair->first)[ft_strchr(envp[i], '=') - envp[i]] = '\0';
		pair->second = ft_strdup(ft_strchr(envp[i], '=') + 1);
		ft_vec_add(&ctrl->env, pair);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	setup_minishell(t_minishell_control *minishell, int ac, char **arg, \
					char **envp)
{
	stifle_history(10);
	ft_setup_prog((const char *const *)arg);
	ft_bzero(minishell, sizeof(t_minishell_control));
	if (create_env(minishell, (const char **)envp) == EXIT_FAILURE)
		return (minishell_error(MINI_ERR_ENVC, NULL, errno), \
		minishell->exit = 1, EXIT_FAILURE);
	minishell_parser_init(minishell);
	return (EXIT_SUCCESS);
}
