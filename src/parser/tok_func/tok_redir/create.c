/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:02:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_math.h"
#include "ft_string.h"
#include "parser_types.h"

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
		if (redir->src_std < 0 || redir->src_std > 1024)
			return (ctx->unexpected = "Invalid file descriptor", false);
		cr_offset += ft_log(redir->src_std) + 1;
		redir->flag = RDIR_STD;
	}
	if (ctx->line[cr_offset] == '>')
		redir->redir_type = RDIR_OUTPUT;
	else if (ctx->line[cr_offset] == '<')
		redir->redir_type = RDIR_INPUT;
	cr_offset++;
	if (ctx->line[cr_offset] && ft_strchr("<>", ctx->line[cr_offset]))
		redir->redir_type |= RDIR_APPEND, cr_offset++;
	else
		redir->redir_type |= RDIR_TRUNC;
	int fd = -1;
	if (ctx->line[cr_offset] && ft_strchr("&", ctx->line[cr_offset]))
	{
		redir->redir_type |= RDIR_DUP;
		cr_offset++;
	}
	if (ft_isdigit(ctx->line[cr_offset]))
	{
		fd = ft_atoi(ctx->line + cr_offset);
		if (fd < 0 || fd > 1024)
			return (ctx->unexpected = "Invalid file descriptor", false);
		cr_offset += ft_log(fd);
		redir->target_std = fd;
	}
	if (fd == -1)
		redir->target_std = 1;
	return (true);
}
