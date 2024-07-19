/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/19 22:07:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "ft_vector_types.h"
#include "minishell.h"
#include "parser.h"
#include "parser_types.h"

#include <stdio.h>
#include <fcntl.h>

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

static bool	loop_body(t_cmd_to_exec *cmd, t_vector *preparsed_tokens,
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

void cr_file(int i, t_vector *prep)
{
	t_preparsed_node	*nd;
	t_redir				*redir;
	char *fname = NULL;

	nd = ft_vec_at(prep, i);
	redir = nd->value;
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		return ;
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT)
	{
		while (nd && (nd->type != TOK_WORD && nd->type != TOK_QUOTE))
			nd = ft_vec_at(prep, i++);
		if (nd->type == TOK_WORD)
			fname = ((t_string *)nd->value)->str;
		else if (nd->type == TOK_QUOTE)
			fname = ((t_quote_node *)nd->value)->value->str;
		if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_TRUNC)
			open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			open(fname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
}

void file_creation(t_vector *prep)
{
	t_preparsed_node	*token;
	int					i;

	i = 0;
	while (prep && (size_t)i < prep->count)
	{
		token = ft_vec_at(prep, i);
		if (token->type == TOK_REDIR)
			cr_file(i, prep);
		i++;
	}
}

t_cmd_to_exec	*parser_get_cmd(t_vector *prep, t_minishell_control *sh)
{
	t_cmd_to_exec		*cmd;
	t_syntax			syntax;

	if (prep == NULL || prep->count == 0)
		return (NULL);
	syntax = syntax_check(prep);
	if (syntax != E_NONE)
		return (print_syntax_error(syntax), file_creation(prep), \
		ft_vec_apply(prep, call_destroy), \
		ft_vec_destroy(&sh->preparsed), prep = NULL, NULL);
	cmd = init_cmd();
	if (cmd == NULL)
		return (NULL);
	if (loop_body(cmd, prep, sh) == false)
		return (NULL);
	return (cmd);
}
