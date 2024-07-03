/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 15:56:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"
#include "ft_list.h"
#include "tokens_funcs.h"
#include <stdio.h>

/*
 		if (paths[i][ft_strlen(paths[i])] == '/')
			path = ft_strdup(paths[i]); 
		else
			path = ft_strjoin(paths[i], "/"); check if ever called
*/

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

bool	nd2ex_pipe(t_preparsed_node *nd, t_cmd_to_exec *cmd,
		t_minishell_control *sh)
{
	t_redir	*rd;

	(void)sh;
	printf("PIPE nd2ex called\n");
	if (nd->type != TOK_PIPE)
		return (false);
	rd = ft_calloc(1, sizeof(t_redir));
	if (!rd)
		return (false);
	rd->src_std = STDOUT_FILENO;
	rd->target_std = STDIN_FILENO;
	rd->redir_type = RDIR_PIPE;
	rd->flag = RDIR_STD;
	if (ft_ll_push(&cmd->redir_to_do, rd) == NULL)
		return (false);
	return (nd2ex_eol(nd, cmd, sh));
}
