/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/22 10:49:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "parser_types.h"

bool	prepn_word_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	const	char	*stoper = "'\"|";
	size_t			cr_offset;

	cr_offset = ctx->line_offset;
	node->type = TOK_WORD;
	node->value = ft_string_new(1);
	while (ctx->line[cr_offset] && !ft_isspace(ctx->line[cr_offset]) 
	&& ft_strchr(stoper, ctx->line[cr_offset]) == NULL)
	{
		if (ctx->line[cr_offset] == '\\' && ctx->line[cr_offset + 1] != '\0')
			cr_offset++;
		if (ft_string_append_c(node->value, ctx->line[cr_offset]))
			return (false);
		cr_offset++;
	}
	return (true);
}
