/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:20:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:35:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"
#include "parser_types.h"
#include <stdlib.h>

// TODO:
// Move init to shell init -
//  currently allocates memory for tokens handlers
//  and adds token handlers to the vector at
//  each call to the parser... so for each lines...
//  this is not good, we should only do this once
// This table of tokens is constant and should be initialized
//  as such, when moving this to shell init, we should also
//  set it as such.
int	parser_init_tokens_handlers(t_parser *prs)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (-1);
	token->type = TOKEN_SPACE;
	token->flag = TOK_FLG_SINGLE;
	ft_strlcpy(token->token, " ", 2);
	token->handler = token_space_handler;
	ft_vec_add(&prs->tokens_handlers, token);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (-1);
	token->type = TOKEN_EOL;
	token->flag = TOK_FLG_SINGLE;
	ft_strlcpy(token->token, "\n", 2);
	token->handler = token_space_handler;
	ft_vec_add(&prs->tokens_handlers, token);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (-1);
	token->type = TOKEN_QUOTE_ALL;
	token->flag = TOK_FLG_SINGLE;
	ft_strlcpy(token->token, "\"", 2);
	token->handler = token_quote_all_handler;
	ft_vec_add(&prs->tokens_handlers, token);
	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (-1);
	token->type = TOKEN_QUOTE_ALL;
	token->flag = TOK_FLG_SINGLE;
	ft_strlcpy(token->token, "'", 2);
	token->handler = token_quote_all_handler;
	ft_vec_add(&prs->tokens_handlers, token);
	return (0);
}

int	init_parser(t_parser *prs)
{
	ft_bzero(prs, sizeof(t_parser));
	prs->words = ft_vec_new();
	prs->tokens_handlers = ft_vec_new();
	parser_init_tokens_handlers(prs);
	return (0);
}
