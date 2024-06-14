/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 18:26:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_types.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include "ft_string.h"
#include "ft_vector.h"
#include <stdio.h>

static char *resolve_cmd(char *cmd, t_minishell_control	*sh)
{
	const char *p = get_env(sh->env, "PATH");
	char **paths;
	char *path;
	char *fullpath;

	if (p == NULL || ft_strchr(cmd, '/') != NULL)
		return (cmd);
	paths = ft_split(p, ':');
	if (paths == NULL)
		return (cmd);
	for (size_t i = 0; paths[i]; i++)
	{
		if (paths[i][ft_strlen(paths[i])] == '/')
			path = ft_strdup(paths[i]);
		else
			path = ft_strjoin(paths[i], "/");
		fullpath = ft_strjoin(path, cmd);
		free(path);
		if (access(fullpath, X_OK) == 0)
			return (ft_free_2d((void **)paths), fullpath);
		free(fullpath);
	}
	return (ft_free_2d((void **)paths), NULL);
}

t_cmd	*parser_get_cmd(t_vector *preparsed_tokens, t_minishell_control *sh)
{
	t_cmd		*cmd;
	t_vector	*args;
	t_preparsed_node	*token;

	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	args = ft_vec_new();
	while (preparsed_tokens->count)
	{
		token = ft_vec_at(preparsed_tokens, 0);
		if (token->type == TOK_WORD)
		{
			ft_vec_add(&args, ((t_string *)token->value)->str);
			ft_vec_shift(preparsed_tokens, 0, 1);
		}
		else if (token->type == TOK_EOL)
		{
			free(token);
			ft_vec_shift(preparsed_tokens, 0, 1);
			break ;
		}
		else
			ft_vec_shift(preparsed_tokens, 0, 1);
		if (token->value)
			free(token->value);
		free(token);
	}
	cmd->argc = args->count;
	cmd->args = (char **)ft_vec_to_array(&args);
	cmd->cmd = resolve_cmd(cmd->args[0], sh);
	cmd->envp = get_bourne_env(sh->env);
	return (cmd);
}
