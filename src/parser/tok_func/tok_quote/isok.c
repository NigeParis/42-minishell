/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 14:29:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_funcs.h"
#include "parser_types.h"

bool	isok_quote(const char *line, t_preparser_context *ctx)
{
	if (ctx->quote_ctx == QUOTE_NONE && (*line == '\"' || \
	*line == '\''))
		return (true);
	if (ctx->quote_ctx == QUOTE_DQUOTE && *line == '\"')
		return (true);
	if (ctx->quote_ctx == QUOTE_SQUOTE && *line == '\'')
		return (true);
	return (false);
}
