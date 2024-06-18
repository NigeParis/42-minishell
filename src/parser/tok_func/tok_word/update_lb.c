/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 12:56:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdio.h>

bool prepn_word_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	if (node->value == NULL)
		return (false);
	ctx->line_offset += ((t_string *)node->value)->length;
	return (true);
}
