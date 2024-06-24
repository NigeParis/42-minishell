/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 10:37:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"
#include "tokens_funcs.h"
#include <stdio.h>

bool	set_quote_value(t_quote_node *quote, t_preparser_context *ctx)
{
	size_t	ln_offset;

	quote->value = ft_string_new(1);
	if (quote->value == NULL)
		return (free(quote), false);
	ln_offset = ctx->line_offset + 1;
	while (ctx->line[ln_offset] != ctx->line[ctx->line_offset] && \
	ctx->line[ln_offset] != '\0')
	{
		if (ctx->line[ln_offset] == '\\')
			ln_offset++;
		if (ft_string_append_c(quote->value, ctx->line[ln_offset]))
			return (false);
		ln_offset++;
	}
	if (ctx->line[ln_offset] == ctx->line[ctx->line_offset])
		ctx->quote_ctx = QUOTE_NONE;
	if (ctx->line[ln_offset] == '\0')
		return (
		ctx->unexpected = "Missing matching quote",
		false);
	return (true);
}

bool	prepn_quote_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_quote_node	*quote;

	node->type = TOK_QUOTE;
	if (ctx->quote_ctx != QUOTE_NONE)
		return (false);
	if (ctx->line[ctx->line_offset] == '\'')
		ctx->quote_ctx = QUOTE_SQUOTE;
	else if (ctx->line[ctx->line_offset] == '\"')
		ctx->quote_ctx = QUOTE_DQUOTE;
	node->value = ft_calloc(sizeof(t_quote_node), 1);
	if (node->value == NULL)
		return (false);
	quote = node->value;
	quote->type = ctx->quote_ctx;
	return (set_quote_value(quote, ctx));
}
