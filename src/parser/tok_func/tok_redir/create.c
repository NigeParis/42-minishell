/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/14 14:08:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_math.h"
#include "ft_string.h"
#include "parser_types.h"

#include <unistd.h>
#define MAX_FD_RDIR 1024

static bool	f_part(t_preparser_context *ctx, size_t *cr_offset_real,
		t_redir *redir)
{
	int	cr_offset;

	cr_offset = *cr_offset_real;
	if (ft_isdigit(ctx->line[cr_offset]))
	{
		redir->src_std = ft_atoi(ctx->line + cr_offset);
		if (redir->src_std < 0 || redir->src_std > MAX_FD_RDIR)
			return (ctx->unexpected = "Invalid file descriptor\n", false);
		cr_offset += ft_log(redir->src_std) + 1;
		redir->flag = RDIR_STD;
	}
	*cr_offset_real = cr_offset;
	return (true);
}

static bool	m_part(t_preparser_context *ctx, t_redir *redir,
			size_t *cr_offset_real)
{
	int	cr_offset;

	cr_offset = *cr_offset_real;
	if (ctx->line[cr_offset] == '>')
		redir->redir_type = RDIR_OUTPUT;
	else if (ctx->line[cr_offset] == '<')
		redir->redir_type = RDIR_INPUT;
	cr_offset++;
	if (ctx->line[cr_offset] && \
	ctx->line[cr_offset - 1] == ctx->line[cr_offset])
		redir->redir_type |= (cr_offset++, RDIR_APPEND);
	else if (ft_strchr("<>", ctx->line[cr_offset]))
		return (ctx->unexpected = "syntax error near redirect\n", false);
	else
		redir->redir_type |= RDIR_TRUNC;
	if (ctx->line[cr_offset] && ft_strchr("<>", ctx->line[cr_offset]))
		return (ctx->unexpected = "syntax error near redirect\n", false);
	if (ctx->line[cr_offset] && ft_strchr("&", ctx->line[cr_offset]))
		redir->redir_type |= (cr_offset++, RDIR_DUP);
	*cr_offset_real = cr_offset;
	return (true);
}

static bool	l_part(t_preparser_context *ctx, t_redir *redir,
			size_t *cr_offset_real)
{
	size_t	cr_offset;

	cr_offset = *cr_offset_real;
	redir->target_std = -1;
	if (redir->redir_type & RDIR_DUP)
	{
		redir->target_std = ft_atoi(ctx->line + cr_offset);
		if (redir->target_std < 0 || redir->target_std > MAX_FD_RDIR)
			return (ctx->unexpected = "Invalid file descriptor\n", false);
		cr_offset += ft_log(redir->target_std);
	}
	*cr_offset_real = cr_offset;
	return (true);
}

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
	if (!f_part(ctx, &cr_offset, redir))
		return (false);
	if (!m_part(ctx, redir, &cr_offset))
		return (false);
	if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND
		&& redir->redir_type & RDIR_MSK_DUP)
		return (ctx->unexpected = "r near '&'\n", false);
	if (redir->redir_type == (RDIR_APPEND | RDIR_INPUT))
		redir->redir_type = RDIR_HEREDOC;
	if (!l_part(ctx, redir, &cr_offset))
		return (false);
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT && !redir->src_std)
		redir->src_std = 1;
	return (true);
}
