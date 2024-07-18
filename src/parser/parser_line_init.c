/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 13:58:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_args.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"

#include <stdbool.h>
#include <stdio.h>

/*
		node = ft_vec_end(p->preparsed); // get last node
		if (node->append(node, ctx) == false)	// append to last node the 
												// current token 
												// (shouldn't be called very 
												// often)
		--
		node = preparsed_node_factory(ctx->n_tok->type);	// create new node 
															// from token using
															// template in
															// node_factory
*/
int	update_preparsed(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_preparsed_node	*node;

	if (ctx->c_tok && ctx->n_tok->type == ctx->c_tok->type)
	{
		node = ft_vec_end(p->preparsed);
		if (node->append(node, ctx) == false)
			return (false);
	}
	else
	{
		node = preparsed_node_factory(ctx->n_tok->type);
		if (node == NULL)
			return (false);
		node->type = ctx->n_tok->type;
		if (node->create(node, ctx) == false)
			return (node->destroy(node), false);
		if (ft_vec_add(&p->preparsed, node) == false)
			return (false);
	}
	return (true);
}

int	update_context(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_preparsed_node	*node;

	ctx->c_tok = ctx->n_tok;
	ctx->n_tok = NULL;
	node = ft_vec_end(p->preparsed);
	if (node == NULL)
		return (false);
	if (node->type == TOK_UNKNOWN)
		return (ctx->line_offset++, false);
	if (node->ulb == NULL)
		return (false);
	return (node->ulb(node, ctx));
}

void	preparser_destroy(t_preparser_context *restrict c, t_parser *restrict p)
{
	t_preparsed_node	*node;
	size_t				i;

	i = 0;
	if (c == NULL || p == NULL)
		return ;
	node = ft_vec_at(p->preparsed, 0);
	while (node)
	{
		node->destroy(node);
		node = ft_vec_at(p->preparsed, ++i);
	}
	ft_vec_destroy(&p->preparsed);
	p->preparsed = NULL;
}

/*
** Preparse the line and create a list of preparsed nodes (tokens), the 
** preparsed nodes are stored in the parser structure in a vector.
** Todo: updat parser_destroy to free the preparsed nodes. 
**		(check method destroy on tokens).
** Todo: modify return to return an error code when failing to allocate memory.
*/
/*
			printf("Error: preparse_line: unexpected token: \'%s\'\n", \
			var_ctx.unexpected); // todo add cleanup and ret err code
			printf("Error: preparse_line: update_preparsed or "\
			"update_context failed\n"); // todo add cleanup and ret err code
*/
int	preparse_line(t_parser *restrict p)
{
	t_preparser_context	var_ctx;
	const size_t		len = ft_strlen(p->line);

	ft_bzero(&var_ctx, sizeof(t_preparser_context));
	var_ctx.line = p->line;
	while (var_ctx.line_offset <= len)
	{
		get_next_token(p, &var_ctx);
		if (var_ctx.n_tok->type == TOK_UNKNOWN)
			var_ctx.unexpected = "Error: Unknown token";
		if (var_ctx.unexpected)
			return (printf("%s : %s\n", ft_progname(), var_ctx.unexpected), \
			preparser_destroy(&var_ctx, p), EXIT_FAILURE);
		else if (update_preparsed(p, &var_ctx) == false \
		|| update_context(p, &var_ctx) == false)
		{
			if (var_ctx.unexpected)
				printf("%s: %s\n", ft_progname(), var_ctx.unexpected);
			preparser_destroy(&var_ctx, p);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	parser_line_init(t_parser *restrict prs)
{
	if (!prs)
		return (ft_putendl_fd("Critical error: no parser", STDERR_FILENO), \
		EXIT_FAILURE);
	if (!prs->line)
		return (ft_putendl_fd("Critical Error: parser_line_init: prs->line " \
		"is NULL", STDERR_FILENO), EXIT_FAILURE);
	prs->preparsed = ft_vec_new();
	if (!prs->preparsed)
		return (ft_putendl_fd("Error: parser_line_init: ft_vec_new failed", \
		STDERR_FILENO), EXIT_FAILURE);
	if (preparse_line(prs))
		return (EXIT_FAILURE);
	if (!prs->preparsed)
		return (ft_putendl_fd("Error: parser_line_init: prs->preparsed is " \
		"NULL", STDERR_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
