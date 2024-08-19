/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 09:37:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_string.h"
#include "parser_types.h"

#include <unistd.h>

static bool	f_part(t_preparser_context *ctx, size_t *cr_offset_real,
		t_redir *redir)
{
	int	cr_offset;

	cr_offset = *cr_offset_real;
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
	*cr_offset_real = cr_offset;
	return (true);
}

static bool	l_part(t_preparser_context *ctx, t_redir *redir,
			size_t *cr_offset_real)
{
	size_t	cr_offset;

	cr_offset = *cr_offset_real;
	redir->target_std = -1;
	*cr_offset_real = cr_offset;
	return (true);
}

bool	prepn_redir_create(t_preparsed_node *node, t_preparser_context *ctx)
{
	t_redir	*redir;
	size_t	cr_offset;

	node->type = TOK_REDIR;
	node->value = ft_calloc(sizeof(t_redir), 1);
	if (!node->value)
		return (false);
	redir = node->value;
	cr_offset = ctx->line_offset;
	redir->redir_type = 0;
	redir->flag = RDIR_FILE;
	if (!f_part(ctx, &cr_offset, redir))
		return (false);
	if (!m_part(ctx, redir, &cr_offset))
		return (false);
	if (redir->redir_type == (RDIR_APPEND | RDIR_INPUT))
		redir->redir_type = RDIR_HEREDOC;
	if (!l_part(ctx, redir, &cr_offset))
		return (false);
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT && !redir->src_std)
		redir->src_std = 1;
	return (true);
}
