/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:00:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

// todo : split in its own file file (called twice)
static char	*resolve_cmd(char *cmd, t_minishell_control *sh)
{
	const char	*p;
	char		**paths;
	char		*path;
	char		*fullpath;
	size_t		i;

	p = get_env(sh->env, "PATH");
	if (!p || ft_strchr(cmd, '/') != NULL)
		return (ft_strdup(cmd));
	paths = ft_split(p, ':');
	if (paths == NULL)
		return (cmd);
	i = 0;
	while (paths[i] != NULL)
	{
		if (paths[i][ft_strlen(paths[i])] == '/')
			path = ft_strdup(paths[i]);
		else
			path = ft_strjoin(paths[i], "/");
		fullpath = ft_strjoin(path, cmd);
		if (free(path), access(fullpath, X_OK) == 0)
			return (ft_free_2d((void **)paths), fullpath);
		(free(fullpath), i++);
	}
	return (ft_free_2d((void **)paths), NULL);
}

bool	nd2ex_eol(t_preparsed_node *nd, t_cmd_to_exec *cmd,
		t_minishell_control *sh)
{
	free(nd);
	if (cmd->construction_vector == NULL)
		return (false);
	cmd->ac = cmd->construction_vector->count;
	cmd->argv = (char **)ft_vec_to_array(&cmd->construction_vector);
	cmd->construction_vector = NULL;
	cmd->cmd_path = resolve_cmd(cmd->argv[0], sh);
	cmd->env = get_bourne_env(sh->env);
	if (!cmd->env || !cmd->argv)
		return (false);
	ft_vec_shift(sh->preparsed, 0, cmd->nb_tok_consumed);
	if (sh->preparsed->count == 0)
		(ft_vec_destroy(&sh->preparsed), sh->preparsed = NULL);
	return (true);
}
