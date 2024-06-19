/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 08:44:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"
#include "tokens_funcs.h"
#include <stdio.h>

bool	prepn_quote_append(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_quote_node	*quote;
	size_t			ln_offset;

	if (node->type != TOK_QUOTE || \
	node->value == NULL)
		return (false);
	quote = node->value;
	if ((quote->type == QUOTE_SQUOTE && ctx->line[ctx->line_offset] != '\'') ||
		(quote->type == QUOTE_DQUOTE && ctx->line[ctx->line_offset] != '\"'))
		return ( // push new quote node of type correct type aka inversed type to current
		false);
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
	return (true);
}
