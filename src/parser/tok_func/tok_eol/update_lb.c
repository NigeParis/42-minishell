/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 12:47:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

bool prepn_eol_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx)
{
	if (ctx->line[ctx->line_offset] == '\n' || ctx->line[ctx->line_offset] == '\0')
		return (ctx->line_offset++, true);
	return (false);
}
