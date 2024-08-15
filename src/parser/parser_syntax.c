/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:45:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/15 13:40:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"

void	print_syntax_error(t_syntax syntax)
{
	ft_putstr_fd("syntax error near unexpected token", STDERR_FILENO);
	if (syntax == E_SYN_PIPE)
		ft_putstr_fd(" '|'\n", STDERR_FILENO);
	else if (syntax == E_SYN_EOL)
		ft_putstr_fd(" '\\n'\n", STDERR_FILENO);
	else if (syntax == E_SYN_REDIR)
		ft_putstr_fd(" 'redirection'\n", STDERR_FILENO);
	else if (syntax == E_SYN_WORD)
		ft_putstr_fd(" 'word'\n", STDERR_FILENO);
}

static t_syntax	loop_body(size_t ctx_v, size_t *wc, t_tok_type type)
{
	if (ctx_v == TOK_REDIR && !(type == TOK_WORD || type == TOK_QUOTE))
		return ((t_syntax)type);
	if (ctx_v != TOK_REDIR && (type == TOK_WORD || type == TOK_QUOTE))
		(*wc)++;
	if (type == TOK_PIPE)
		*wc = 0;
	return (E_SYN_NONE);
}

t_syntax	syntax_check(t_vector *prep)
{
	size_t				stx_it;
	size_t				ctx_v;
	size_t				wc;
	t_preparsed_node	*token;

	stx_it = 0;
	ctx_v = TOK_SPACE;
	while (ctx_v == TOK_SPACE && prep && stx_it < prep->count)
		ctx_v = ((t_preparsed_node *)ft_vec_at(prep, stx_it++))->type;
	wc = (ctx_v == TOK_WORD || ctx_v == TOK_QUOTE);
	while (prep && stx_it < prep->count)
	{
		token = ft_vec_at(prep, stx_it++);
		if (token->type == TOK_SPACE)
			continue ;
		loop_body(ctx_v, &wc, token->type);
		ctx_v = token->type;
	}
	if (ctx_v == TOK_PIPE || ctx_v == TOK_REDIR)
		return ((t_syntax)token->type);
	if (wc == 0 && ctx_v != TOK_WORD && ctx_v != TOK_QUOTE)
		return (E_SYN_EOL);
	return (E_SYN_NONE);
}
