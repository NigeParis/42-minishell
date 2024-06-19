/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 10:49:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

bool	isok_pipe(const char *line, t_preparser_context *ctx)
{
	if (ctx->quote_ctx == QUOTE_SQUOTE || ctx->quote_ctx == QUOTE_DQUOTE)
		return (false);
	return (*line == '|');
}
