/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 12:53:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "parser_types.h"

bool prepn_space_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx)
{
	if (ft_isspace(ctx->line[ctx->line_offset]))
	{
		ctx->line_offset++;
		return (true);
	}
	return (false);
}

