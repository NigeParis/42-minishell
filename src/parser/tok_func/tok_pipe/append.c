/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 13:52:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

bool	prepn_pipe_append(t_preparsed_node *node, t_preparser_context *ctx)
{
	(void)node;
	(void)ctx;
	ctx->unexpected = ": Unexpected token '||'";
	return (false);
}
