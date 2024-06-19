/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 10:48:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdio.h>

bool prepn_pipe_ulb(t_preparsed_node *node, t_preparser_context *ctx)
{
	(void)node;
	ctx->line_offset++;
	return (true);
}
