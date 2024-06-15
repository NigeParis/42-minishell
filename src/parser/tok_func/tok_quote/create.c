/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 16:17:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include "tokens_funcs.h"

bool	prepn_quote_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	node->type = TOK_QUOTE;
	node->value = NULL;
	ctx->quote_ctx = QUOTE_NONE;
	if (ctx->line[ctx->line_offset] == '\'')
		ctx->quote_ctx = QUOTE_SQUOTE;
	else if (ctx->line[ctx->line_offset] == '\"')
		ctx->quote_ctx = QUOTE_DQUOTE;
	node->value = (void *)ctx->quote_ctx;
	return (true);
}
