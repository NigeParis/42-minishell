/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:32:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "parser_types.h"

bool	prepn_redir_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	size_t	cr_offset;

	cr_offset = ctx->line_offset;
	while (ft_isdigit(ctx->line[cr_offset]) && ctx->line[cr_offset] != '\0')
		cr_offset++;
	while (ft_strchr("<>", ctx->line[cr_offset]) != NULL && \
	ctx->line[cr_offset])
		cr_offset++;
	if (ft_strchr("&", ctx->line[cr_offset]) != NULL && ctx->line[cr_offset])
		cr_offset++;
	while (ft_isdigit(ctx->line[cr_offset]) && ctx->line[cr_offset] != '\0')
		cr_offset++;
	ctx->line_offset = cr_offset;
	return (true);
}
