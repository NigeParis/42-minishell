/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsed_node_factory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:22:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_types.h"
#include "tokens_funcs.h"
#include <stdio.h>
#include <stdlib.h>

static const t_preparsed_node	g_preparser_nodes_tb[] = {
{TOK_PIPE, NULL, prepn_pipe_create, prepn_pipe_ulb, prepn_pipe_append,
	prepn_pipe_print, destroy_pipe, nd2ex_pipe},
{TOK_REDIR, NULL, prepn_redir_create, prepn_redir_ulb, prepn_redir_append,
	prepn_redir_print, destroy_redir, nd2ex_redir},
{TOK_WORD, NULL, prepn_word_create, prepn_word_ulb, prepn_word_append,
	prepn_word_print, destroy_word, nd2ex_word},
{TOK_SPACE, NULL, prepn_space_create, prepn_space_ulb, prepn_space_append,
	prepn_space_print, destroy_space, nd2ex_space},
{TOK_EOL, NULL, prepn_eol_create, prepn_eol_ulb, prepn_eol_append,
	prepn_eol_print, destroy_eol, nd2ex_eol},
{TOK_QUOTE, NULL, prepn_quote_create, prepn_quote_ulb, prepn_quote_append,
	prepn_quote_print, destroy_quote, nd2ex_quote},
{TOK_UNKNOWN, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
};

static void	set_functions(t_preparsed_node *node)
{
	size_t	i;

	i = 0;
	while (g_preparser_nodes_tb[i].type != TOK_UNKNOWN)
	{
		if (g_preparser_nodes_tb[i].type == node->type)
		{
			node->create = g_preparser_nodes_tb[i].create;
			node->ulb = g_preparser_nodes_tb[i].ulb;
			node->print = g_preparser_nodes_tb[i].print;
			node->append = g_preparser_nodes_tb[i].append;
			node->destroy = g_preparser_nodes_tb[i].destroy;
			node->execute = g_preparser_nodes_tb[i].execute;
			return ;
		}
		i++;
	}
}

/*
** Create a new preparsed node from a token type
**
** todo: add error handling, currently fails if token = TOK_UNKNOWN
*/
t_preparsed_node	*preparsed_node_factory(t_tok_type type)
{
	t_preparsed_node	*node;

	node = (t_preparsed_node *)malloc(sizeof(t_preparsed_node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->value = NULL;
	set_functions(node);
	return (node);
}
