/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_glob_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:45 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 13:15:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector_types.h"
#include "parser_types.h"
#include "parser.h"
#include "ft_vector.h"
#include <stdio.h>
#include <stdlib.h>

static t_token	*load_tokens(void)
{
	static const t_token	tokens[] = {
/*
		{TOK_PIPE, "|"},
		{TOK_SEMICOLON, ";"},
		{TOK_AND, "&&"},
		{TOK_OR, "||"},
*/
		{TOK_EOL, "\n", isok_eol},
		{TOK_WORD, NULL, isok_word},
		{TOK_SPACE, " ", isok_space},
		{TOK_UNKNOWN, NULL, NULL},
	};

	return ((t_token *)tokens);
}

int	parser_glob_init(t_parser *prs)
{
	const t_token	*tok = load_tokens();
	size_t			i;

	prs->res = NULL;
	prs->line = NULL;
	prs->tokens = NULL;
	prs->tokens = ft_vec_from_size(TOK_UNKNOWN + 1);
	if (prs->tokens == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < TOK_UNKNOWN + 1)
		ft_vec_add(&prs->tokens, (void *)&tok[i++]);
	prs->preparsed = NULL;
	return (EXIT_SUCCESS);
}
