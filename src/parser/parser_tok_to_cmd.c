/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:46:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "parser.h"

#include <stdio.h>

void	call_destroy(void *data)
{
	t_preparsed_node	*token;

	token = data;
	if (token && token->destroy)
		token->destroy(token);
}

t_cmd_to_exec	*init_cmd(void)
{
	t_cmd_to_exec	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->construction_vector = ft_vec_new();
	cmd->construction_index = 0;
	if (cmd->construction_vector == NULL)
		return (free(cmd), NULL);
	return (cmd);
}

bool	loop_body(t_cmd_to_exec *cmd, t_vector *preparsed_tokens,
		t_minishell_control *sh)
{
	t_preparsed_node	*token;
	bool				cmd_rdy;

	cmd_rdy = false;
	while (!cmd->cmd_path && sh->preparsed && \
	preparsed_tokens->count > cmd->nb_tok_consumed && cmd_rdy == false)
	{
		token = ft_vec_at(preparsed_tokens, cmd->nb_tok_consumed++);
		if (token && token->execute)
		{
			if (token->type == TOK_EOL || token->type == TOK_PIPE)
				cmd_rdy = true;
			if (token->execute(token, cmd, sh) == false)
				return (discard_cmd(cmd), false);
		}
		else
		{
			if (token)
				token->print(token);
			return (false);
		}
	}
	return (true);
}

t_cmd_to_exec	*parser_get_cmd(t_vector *preparsed_tokens,
		t_minishell_control *sh)
{
	t_cmd_to_exec		*cmd;
	t_syntax			syntax;

	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	syntax = syntax_check(preparsed_tokens);
	if (syntax != E_NONE)
		return (print_syntax_error(syntax), \
		ft_vec_apply(preparsed_tokens, call_destroy), \
		ft_vec_destroy(&sh->preparsed), preparsed_tokens = NULL, NULL);
	cmd = init_cmd();
	if (cmd == NULL)
		return (NULL);
	if (loop_body(cmd, preparsed_tokens, sh) == false)
		return (NULL);
	return (cmd);
}
