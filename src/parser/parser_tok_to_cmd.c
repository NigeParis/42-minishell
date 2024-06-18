/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tok_to_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:12:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_types.h"
#include "ft_vector_types.h"
#include "minishell_types.h"
#include "parser_types.h"
#include "ft_string.h"
#include "ft_vector.h"
#include <stdio.h>

static void debug_n_list(t_vector *tokens)
{
	size_t i = 0;
	t_preparsed_node *node;

	while (i < tokens->count)
	{
		node = ft_vec_at(tokens, i++);
		node->print(node);
	}
	printf("\n");
}

// to fix -
//  - currently auto jumps to next word
//   - should not.
t_cmd_to_exec	*parser_get_cmd(t_vector *preparsed_tokens, t_minishell_control *sh)
{
	t_cmd_to_exec		*cmd;
	t_vector			*args;
	t_preparsed_node	*token;

	printf("parser_get_cmd\n");
	printf("preparsed_tokens %p\n", preparsed_tokens);
	if (preparsed_tokens == NULL || preparsed_tokens->count == 0)
		return (NULL);
	if (1)
		debug_n_list(preparsed_tokens);
	cmd = ft_calloc(1, sizeof(*cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->construction_vector = ft_vec_new();
	cmd->construction_index = 0;
	while (sh->preparsed && preparsed_tokens->count > cmd->nb_tok_consumed)
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
	return (cmd);
}
