/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pl_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:56:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 12:58:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_vector.h"

#include "parser.h"

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
