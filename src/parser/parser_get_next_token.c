/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_next_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:39:44 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:40:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_vector.h"
#include "parser_types.h"

//	ctx->n_tok = ft_vec_end(p->tokens); // default to unknown
void	get_next_token(t_parser *restrict p, t_preparser_context *restrict ctx)
{
	t_token	*tok;
	size_t	i;

	i = 0;
	ctx->n_tok = ft_vec_end(p->tokens);
	while (i < p->tokens->count)
	{
		tok = ft_vec_at(p->tokens, i++);
		if (tok->validator && \
		tok->validator(ctx->line + ctx->line_offset, ctx) == true)
			return ((void)(ctx->n_tok = tok));
	}
}
