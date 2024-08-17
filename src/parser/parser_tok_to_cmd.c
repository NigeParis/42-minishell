/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/17 11:11:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"
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
		sh->nb_tok_consumed++;
		if (token && token->execute)
		{
			if (token->type == TOK_EOL || token->type == TOK_PIPE)
				cmd_rdy = true;
			if (token->execute(token, cmd, sh) == false)
				return (discard_cmd(cmd), false);
		}
		else
			return (false);
	}
	return (true);
}

bool	get_target_file(t_redir *rdr, t_vector *tok, int offset)
{
	t_preparsed_node	*next_tok;
	t_string			*str;

	next_tok = ft_vec_at(tok, ++offset);
	while (next_tok && !(next_tok->type == TOK_WORD
			|| next_tok->type == TOK_QUOTE))
		next_tok = ft_vec_at(tok, ++offset);
	if (next_tok == NULL)
		return (false);
	str = next_tok->value;
	rdr->target_file = ft_string_to_str(str);
	return (rdr->target_file != NULL);
}

void	do_emptylines_hdoc(t_vector *prep)
{
	t_preparsed_node	*token;
	t_redir				*redir;
	int					i;

	i = 0;
	while (prep && (size_t)i < prep->count)
	{
		token = ft_vec_at(prep, i);
		if (token && token->type == TOK_REDIR)
		{
			redir = token->value;
			if ((!redir->target_file) && (redir->redir_type != RDIR_HEREDOC))
				return ;
			if (redir->target_file == NULL && get_target_file(redir, \
				prep, i) == false)
				return ;
			if (redir->redir_type == RDIR_HEREDOC)
				do_heredoc(redir, false);
		}
		i++;
	}
}

t_cmd_to_exec	*parser_get_cmd(t_vector *prep, t_minishell_control *sh)
{
	t_cmd_to_exec	*cmd;
	t_syntax		syntax;

	if (prep == NULL || prep->count == 0)
		return (NULL);
	syntax = syntax_check(prep);
	if (syntax != E_SYN_NONE)
		return (print_syntax_error(syntax), file_creation(prep), \
		do_emptylines_hdoc(prep), ft_vec_apply(prep, call_destroy), \
		ft_vec_destroy(&sh->preparsed), prep = NULL, sh->exit = 2, NULL);
	cmd = init_cmd();
	if (!cmd || loop_body(cmd, prep, sh) == false)
		return (NULL);
	return (cmd);
}
