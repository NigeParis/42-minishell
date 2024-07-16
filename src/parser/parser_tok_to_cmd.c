/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:38:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_types.h"
#include "ft_vector_types.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include "ft_string.h"
#include "ft_vector.h"

#include <stdio.h>

bool	syntax_check(t_vector *prep)
{
	bool				vars[2];
	t_preparsed_node	*tok;
	size_t				i;

	if (prep == NULL || prep->count == 0)
		return (false);
	i = 0;
	ft_bzero(vars, sizeof(vars));
	while (prep->count > i)
	{
		tok = ft_vec_at(prep, i++);
		if (tok->type == TOK_WORD || tok->type == TOK_QUOTE)
			vars[0] = true;
		else if (tok->type == TOK_PIPE || tok->type == TOK_EOL)
		{
			if (vars[0] == false)
				return (false);
			if (tok->type == TOK_EOL)
				return (true);
			vars[0] = false;
		}
	}
	return (vars[0]);
}

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

void	print_syntax_error(t_vector *preparsed_tokens,
		t_minishell_control *sh)
{
	printf("syntax error :: %p %zu\n", preparsed_tokens,
		preparsed_tokens->count);
	ft_vec_apply(preparsed_tokens, call_destroy);
	ft_vec_destroy(&sh->preparsed);
	preparsed_tokens = NULL;
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

	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	if (syntax_check(preparsed_tokens) == false)
		return (print_syntax_error(preparsed_tokens, sh), NULL);
	cmd = init_cmd();
	if (cmd == NULL)
		return (NULL);
	if (loop_body(cmd, preparsed_tokens, sh) == false)
		return (NULL);
	return (cmd);
}
