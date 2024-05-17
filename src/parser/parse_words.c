/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:22:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:51:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_vector.h"
#include "parser.h"
#include <stdio.h>

static void	dump_words(void *str_d)
{
	char	*str;

	str = (char *)str_d;
	printf("CURRENT WORD BUFFER ::'%s'\n", str);
}

// problem:
// 1. The function returns a char ** but the parser needs to be updated as the 
// line is executed. e.g. $STATUS
// solution:
// 1. At execution time, check if special stuff needs to be done and do it.
// 2. Return a t_line_parser (a new struct) that contains a list of tokens with
// their types and a pointer to the string input at correct offset.
//	2.1: need to separate hit detection from execution.
//	2.2: need to filter out bad hit on special chars.
//		e.g. ' ' in quotes/double quotes.
// conclusion:
// - probably 2.

char	**parse_words(const char *str, t_parser *restrict parser)
{
	int			next_token;
	size_t		token_t;
	char		**ret;

	while (str[parser->str_offset])
	{
		next_token = search_next_token(str + parser->str_offset, parser);
		if (next_token != 0)
			bulk_add_char(parser, str, next_token);
		else
		{
			token_t = get_token_handler(str + parser->str_offset, parser);
			token_handler(token_t, str + parser->str_offset, parser);
		}
		printf("CURRENT OFFSET ::'%zu'\n", parser->str_offset);
		printf("CURRENT STR ::'%s'\n", str + parser->str_offset);
		printf("NEXT TOKEN ::'%d'\n", next_token);
		ft_vec_apply(parser->words, dump_words);
	}
	ret = (char **)ft_vec_to_array(&(parser->words));
	parser->words = NULL;
	return (ret);
}
