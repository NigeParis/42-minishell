/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 13:49:27 by bgoulard         ###   ########.fr       */
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

static void debug_n_list(t_vector *tokens)
{
	size_t i = 0;
	t_preparsed_node *node;

	printf("debug_n_list -- (%p)\n", tokens);
	fflush(stdout);
	if (tokens == NULL)
		return ;
	while (i < tokens->count)
	{
		node = ft_vec_at(tokens, i++);
		node->print(node);
	}
	printf("\n");
}

bool syntax_check(t_vector *prep)
{
	bool vars[2] = {false, false};
	t_preparsed_node *tok;
	size_t i = 0;

	while (prep->count > i)
	{
		tok = ft_vec_at(prep, i++);
		if (tok->type == TOK_WORD)
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

t_cmd_to_exec	*parser_get_cmd(t_vector *preparsed_tokens, t_minishell_control *sh)
{
	t_cmd_to_exec		*cmd;
	t_vector			*args;
	t_preparsed_node	*token;

	if (DEBUG_LVL)
		debug_n_list(preparsed_tokens);
	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	if (syntax_check(preparsed_tokens) == false)
		return ( /* free prep toks here , */ NULL);
	cmd = ft_calloc(1, sizeof(*cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->construction_vector = ft_vec_new();
	cmd->construction_index = 0;
	while (!cmd->cmd_path && sh->preparsed && preparsed_tokens->count > cmd->nb_tok_consumed)
	{
		token = ft_vec_at(preparsed_tokens, cmd->nb_tok_consumed++);
		if (token && token->execute)
			token->execute(token, cmd, sh);
		else
		{
			printf("error: no execute function for token %p\t", token), 
				token->print(token);
			return (NULL);
		}
	}
	if (DEBUG_LVL >= 2)
		printf("dbg :: cmd :: %s\n", cmd->cmd_path);
	return (cmd);
}
