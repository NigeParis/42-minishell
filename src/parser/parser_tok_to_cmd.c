/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:40:52 by bgoulard         ###   ########.fr       */
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

static void	debug_n_list(t_vector *tokens)
{
	size_t				i;
	t_preparsed_node	*node;

	i = 0;
	printf("debug_n_list -- (%p)\n", tokens);
	fflush(stdout);
	if (tokens == NULL)
		return ;
	while (i < tokens->count)
	{
		node = ft_vec_at(tokens, i++);
		printf("(%p) ", node);
		node->print(node);
	}
	printf("\n");
}

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

t_cmd_to_exec	*parser_get_cmd(t_vector *preparsed_tokens,
		t_minishell_control *sh)
{
	t_cmd_to_exec		*cmd;
	t_vector			*args;
	t_preparsed_node	*token;
	bool				cmd_rdy;

	if (DEBUG_LVL >= 20)
		debug_n_list(preparsed_tokens);
	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	if (syntax_check(preparsed_tokens) == false)
		return (
			printf("syntax error :: %p %zu\n", preparsed_tokens, \
				preparsed_tokens->count), \
			ft_vec_apply(preparsed_tokens, call_destroy), \
			ft_vec_destroy(&sh->preparsed), \
			preparsed_tokens = NULL, \
		NULL);
	cmd = ft_calloc(1, sizeof(*cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->construction_vector = ft_vec_new();
	cmd->construction_index = 0;
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
			{
				printf("nd2ex on token failed.\ntoken respossible:\t");
				token->print(token);
				printf("\n");
				ft_vec_shift(sh->preparsed, 0, cmd->nb_tok_consumed - 1);
				debug_n_list(preparsed_tokens);
				discard_cmd(cmd);
				return (NULL);
			}
		}
		else
		{
			printf("error: no execute function for token %p\t", token);
			if (token)
				token->print(token);
			return (NULL);
		}
	}
	if (DEBUG_LVL >= 20)
		printf("dbg :: cmd :: %s\n", cmd->cmd_path);
	return (cmd);
}
