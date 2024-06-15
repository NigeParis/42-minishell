/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 15:54:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include "tokens_funcs.h"

bool	prepn_quote_append(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_quote_node	*quote;

	if (node->type != TOK_QUOTE || \
	node->value == NULL)
		return (false);
	quote = node->value;
	if ((quote->type == QUOTE_SQUOTE && ctx->line[ctx->line_offset] != '\'') ||
		(quote->type == QUOTE_DQUOTE && ctx->line[ctx->line_offset] != '\"'))
		return (false);
	if (quote->type == QUOTE_SQUOTE)
		return (quote->type = QUOTE_NONE, true);
	return (quote->type = QUOTE_NONE, true);
}
