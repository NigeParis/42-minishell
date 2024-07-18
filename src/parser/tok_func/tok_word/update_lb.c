/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:08:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "parser_types.h"

bool	prepn_word_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	const char	*stoper;
	size_t		cr_offset;

	stoper = "'\"|<>";
	cr_offset = ctx->line_offset;
	if (node->value == NULL)
		return (false);
	while (ctx->line[cr_offset] && !ft_isspace(ctx->line[cr_offset])
		&& ft_strchr(stoper, ctx->line[cr_offset]) == NULL)
	{
		cr_offset++;
	}
	ctx->line_offset += ((t_string *)node->value)->length;
	return (true);
}
