/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 15:50:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"

bool	prepn_word_append(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_string	*val;

	if (node->type != TOK_WORD || node->value == NULL)
		return (false);
	val = node->value;
	ft_string_append_c(val, *(ctx->line + ctx->line_offset));
	return (true);
}
