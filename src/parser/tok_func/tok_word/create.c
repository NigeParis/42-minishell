/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 13:42:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"

bool	prepn_word_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	node->type = TOK_WORD;
	node->value = ft_string_new(1);
	ft_string_append_c(node->value, *(ctx->line + ctx->line_offset));
	return (true);
}
