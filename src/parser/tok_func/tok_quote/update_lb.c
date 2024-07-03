/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 14:29:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include "tokens_funcs.h"

bool	prepn_quote_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	size_t	ln_offset;

	ln_offset = ctx->line_offset + 1;
	while (ctx->line[ln_offset] != ctx->line[ctx->line_offset] && \
	ctx->line[ln_offset] != '\0')
	{
		if (ctx->line[ln_offset] == '\\')
			ln_offset++;
		ln_offset++;
	}
	ctx->line_offset = ln_offset + 1;
	return (true);
}
