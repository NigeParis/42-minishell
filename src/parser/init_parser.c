/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:20:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 09:26:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser.h"
#include "parser_types.h"

// TODO:
// This table of tokens is constant and should be initialized
//  as such, set it as such.

int	parser_init_tokens_handlers(t_parser *prs)
{
	size_t					i;
	static const t_token	tokens[] = {
	{TOKEN_SPACE, TOK_FLG_SINGLE, " ", tok_han_space, tok_val_space},
	{TOKEN_SPACE, TOK_FLG_SINGLE, "\t", tok_han_space,  tok_val_space},
	{TOKEN_SPACE, TOK_FLG_SINGLE, "\v", tok_han_space, tok_val_space},
	{TOKEN_SPACE, TOK_FLG_SINGLE, "\r", tok_han_space, tok_val_space},
	{TOKEN_SPACE, TOK_FLG_SINGLE, "\f", tok_han_space, tok_val_space},
	{TOKEN_SPACE, TOK_FLG_SINGLE, "\n", tok_han_space, tok_val_space},
	{TOKEN_QUOTE_ALL, TOK_FLG_SINGLE, "'", tok_han_quote, tok_val_quote},
	{TOKEN_QUOTE_ALL, TOK_FLG_SINGLE, "\"", tok_han_quote, tok_val_quote},
	{TOKEN_STRING_EXPANSION, TOK_FLG_SINGLE, "$", tok_han_doll, tok_val_doll},
	};

	prs->tokens_handlers = ft_vec_new();
	i = 0;
	while (i < sizeof(tokens) / sizeof(t_token))
	{
		ft_vec_add(&prs->tokens_handlers, (void *)&tokens[i]);
		i++;
	}
	return (0);
}

int	init_parser_line(t_parser *prs)
{
	prs->words = ft_vec_new();
	prs->str_offset = 0;
	prs->word_offset = 0;
	prs->quote = QUOTE_NONE;
	return (0);
}
