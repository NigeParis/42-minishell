/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 15:47:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "parser_types.h"
#include <stdio.h>

bool	prepn_word_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	size_t		c_skip;
	const char	*stoper;
	size_t		cr_offset;

	stoper = "'\"|<>";
	c_skip = 0;
	cr_offset = ctx->line_offset;
	if (node->value == NULL)
		return (false);
	while (ctx->line[cr_offset] && !ft_isspace(ctx->line[cr_offset])
		&& ft_strchr(stoper, ctx->line[cr_offset]) == NULL)
	{
		if (ctx->line[cr_offset] == '\\' && ctx->line[cr_offset + 1] != '\0')
		{
			cr_offset++;
			c_skip++;
		}
		cr_offset++;
	}
	ctx->line_offset += ((t_string *)node->value)->length + c_skip;
	return (true);
}
