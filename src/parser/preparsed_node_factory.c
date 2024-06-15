/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparsed_node_factory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 15:39:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_types.h"
#include "tokens_funcs.h"
#include <stdlib.h>

static const t_preparsed_node g_prep_nodes_truth_table[] = {
	{TOK_WORD,	NULL,	prepn_word_create,	prepn_word_update_line_buffer,	prepn_word_append,	prepn_word_print},
	{TOK_SPACE,	NULL,	prepn_space_create,	prepn_space_update_line_buffer,	prepn_space_append,	prepn_space_print},
	{TOK_EOL,	NULL,	prepn_eol_create,	prepn_eol_update_line_buffer,	prepn_eol_append,	prepn_eol_print},
	{TOK_QUOTE,	NULL,	prepn_quote_create,	prepn_quote_update_line_buffer,	prepn_quote_append,	prepn_quote_print},
	{TOK_UNKNOWN, NULL, NULL, NULL, NULL, NULL},
};

static void set_functions(t_preparsed_node *node)
{
	size_t	i;

	i = 0;
	while (g_prep_nodes_truth_table[i].type != TOK_UNKNOWN)
	{
		if (g_prep_nodes_truth_table[i].type == node->type)
		{
			node->create = g_prep_nodes_truth_table[i].create;
			node->update_line_buffer = g_prep_nodes_truth_table[i].update_line_buffer;
			node->print = g_prep_nodes_truth_table[i].print;
			node->append = g_prep_nodes_truth_table[i].append;
			return ;
		}
		i++;
	}
}

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
