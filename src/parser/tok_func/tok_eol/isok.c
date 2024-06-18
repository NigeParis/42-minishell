/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 13:03:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdio.h>

bool	isok_eol(const char *line, t_preparser_context *ctx)
{
	if (ctx->quote_ctx == QUOTE_SQUOTE || ctx->quote_ctx == QUOTE_DQUOTE)
		return (false);
	if (*line == '\n' || *line == '\0')
		return (
		printf("isok_eol dbg *line %c\n", *line),
		true);
	return (false);
}
