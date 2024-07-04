/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 19:33:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_math.h"
#include "ft_string.h"
#include "parser_types.h"
#include <unistd.h>
#define MAX_FD_RDIR 1024

bool	prepn_redir_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_redir	*redir;
	size_t	cr_offset;

	node->type = TOK_REDIR;
	node->value = ft_calloc(sizeof(t_redir), 1);
	redir = node->value;
	cr_offset = ctx->line_offset;
	redir->redir_type = 0;
	redir->flag = RDIR_FILE;
	if (ft_isdigit(ctx->line[cr_offset]))
	{
		redir->src_std = ft_atoi(ctx->line + cr_offset);
		if (redir->src_std < 0 || redir->src_std > MAX_FD_RDIR)
			return (ctx->unexpected = "Invalid file descriptor", false);
		cr_offset += ft_log(redir->src_std) + 1;
		redir->flag = RDIR_STD;
	}
	if (ctx->line[cr_offset] == '>')
	{
		redir->redir_type = RDIR_OUTPUT;
		if (redir->src_std == 0)
			redir->src_std = 1;
	}
	else if (ctx->line[cr_offset] == '<')
		redir->redir_type = RDIR_INPUT;
	cr_offset++;
	if (ctx->line[cr_offset] && ft_strchr("<>", ctx->line[cr_offset]))
		redir->redir_type |= RDIR_APPEND, cr_offset++;
	else
		redir->redir_type |= RDIR_TRUNC;
	if (redir->redir_type == (RDIR_APPEND | RDIR_INPUT))
		redir->redir_type = RDIR_HEREDOC;
	redir->target_std = -1;
	if (ctx->line[cr_offset] && ft_strchr("&", ctx->line[cr_offset]))
	{
		redir->redir_type |= RDIR_DUP;
		cr_offset++;
	}
	if (ft_isdigit(ctx->line[cr_offset]))
	{
		redir->target_std = ft_atoi(ctx->line + cr_offset);
		if (redir->target_std < 0 || redir->target_std > MAX_FD_RDIR)
			return (ctx->unexpected = "Invalid file descriptor", false);
		cr_offset += ft_log(redir->target_std);
	}
	return (true);
}
