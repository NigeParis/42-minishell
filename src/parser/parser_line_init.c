/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 16:24:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include "parser.h"
#include "parser_types.h"
#include "ft_vector_types.h"
#include "ft_vector.h"
#include "ft_string.h"
#include "ft_addons.h"
#include <stdio.h>
#include <stdlib.h>

static char *singleton_line(char *restrict line, bool set)
{
	static char *singleton = NULL;

	if (set == true)
		singleton = line;
	return (singleton);
}

int	tok_cmpvalue(const void *a, const void *b)
{
	const t_token	*tok = b;
	const char		*val = a;

	if (tok->value == NULL)
		return (1);
	return (ft_strcmp(val, tok->value));
}

void	custom_map(t_vector **vec, t_vector *restrict tokens, char *line, t_preparser_context *restrict ctx)
{
	size_t	i;
	t_token	*tok_eval;

	i = 0;
	while (i < tokens->count)
	{
		tok_eval = ft_vec_at(tokens, i);
		if (tok_eval->validator && tok_eval->validator(line, ctx) == true)
			ft_vec_add(vec, new_pair((void *)i, (void *)ft_vec_at(tokens, i)));
		i++;
	}
}

void	get_next_token(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_vector	*tok_proximity;
	t_pair		*min;
	t_pair		*eval;

	tok_proximity = ft_vec_from_size(p->tokens->count);
	custom_map(&tok_proximity, p->tokens, p->line + ctx->line_offset, ctx);
	min = ft_vec_pop(tok_proximity);
	while (tok_proximity->count > 0)
	{
		eval = ft_vec_pop(tok_proximity);
		if (eval->first < min->first)
			free(min), min = eval;
		else
			free(eval);
	}
	ft_vec_destroy(&tok_proximity);
	if (min == NULL)
	{
		ctx->unexpected = ft_strndup(p->line + ctx->line_offset, 1);
		ctx->n_tok = ft_vec_at(p->tokens, TOK_UNKNOWN);
	}
	else
		ctx->n_tok = min->second;
	free(min);
}

int	update_preparsed(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_preparsed_node	*node;

	if (ctx->c_tok && ctx->n_tok->type == ctx->c_tok->type)
	{
		node = ft_vec_end(p->preparsed);
		node->append(node, ctx);
	}
	else
	{
		node = preparsed_node_factory(ctx->n_tok->type);
		if (node == NULL)
			return (false);
		node->type = ctx->n_tok->type;
		node->create(node, ctx);
		ft_vec_add(&p->preparsed, node);
	}
	return (true);
}

int update_context(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_preparsed_node	*node;

	ctx->c_tok = ctx->n_tok;
	ctx->n_tok = NULL;
	node = ft_vec_end(p->preparsed);
	if (node == NULL)
		return (false);
	if (node->type == TOK_UNKNOWN)
		return (ctx->line_offset++, true);
	if (node->update_line_buffer == NULL)
		return (false);
	return (node->update_line_buffer(node, ctx));
}

void	preparse_line(t_parser *restrict p)
{
	t_preparser_context	var_ctx;
	const size_t		len = ft_strlen(p->line);
	int					dbg = 2;

	ft_bzero(&var_ctx, sizeof(t_preparser_context));
	var_ctx.line = p->line;
	while (var_ctx.line_offset <= len)
	{
		get_next_token(p, &var_ctx);
		if (var_ctx.n_tok->type == TOK_UNKNOWN)
			ft_putendl_fd("Error: preparse_line: unknown token", \
			STDERR_FILENO);
		else if (var_ctx.unexpected)
			printf("Error: preparse_line: unexpected token: \'%s\'\n", \
			var_ctx.unexpected);
		else
		{
			if (update_preparsed(p, &var_ctx) == false 
			|| update_context(p, &var_ctx) == false)
				printf("Error: preparse_line: update_preparsed or "\
				"update_context failed\n");
		}
/*		((t_preparsed_node *)ft_vec_end(p->preparsed))->print( \
			ft_vec_end(p->preparsed));
		printf("\n"); */
	}
}

int	parser_line_init(t_parser *restrict prs)
{
	if (!prs)
		return (ft_putendl_fd("Critical error: no parser", STDERR_FILENO), \
		EXIT_FAILURE);
	if (!prs->line)
		return (ft_putendl_fd("Error: parser_line_init: prs->line is NULL", \
		STDERR_FILENO), EXIT_FAILURE);
	prs->preparsed = ft_vec_new();
	preparse_line(prs);
	if (!prs->preparsed)
		return (ft_putendl_fd("Error: parser_line_init: prs->preparsed is " \
		"NULL", STDERR_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
