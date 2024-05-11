/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:20:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 13:38:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser.h"
#include "parser_types.h"
#include <stdio.h>

// TODO:
// This table of tokens is constant and should be initialized
//  as such, set it as such.

int	parser_init_tokens_handlers(t_parser *prs)
{
	static const t_token	tokens[] = {
		{TOKEN_SPACE, TOK_FLG_SINGLE, " ", token_space_handler},
		{TOKEN_SPACE, TOK_FLG_SINGLE, "\t", token_space_handler},
		{TOKEN_SPACE, TOK_FLG_SINGLE, "\v", token_space_handler},
		{TOKEN_SPACE, TOK_FLG_SINGLE, "\r", token_space_handler},
		{TOKEN_SPACE, TOK_FLG_SINGLE, "\f", token_space_handler},
		{TOKEN_SPACE, TOK_FLG_SINGLE, "\n", token_space_handler},
		{TOKEN_QUOTE_ALL, TOK_FLG_SINGLE, "'", token_quote_all_handler},
		{TOKEN_QUOTE_ALL, TOK_FLG_SINGLE, "\"", token_quote_all_handler},
	};
	size_t			i;

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
	for (size_t debug= 0; debug < prs->tokens_handlers->count; debug++)
	{
		printf("token: %p\n", prs->tokens_handlers->datas[debug]);
	}
	return (0);
}
