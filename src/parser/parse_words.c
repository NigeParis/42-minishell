/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:22:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 15:41:47 by bgoulard         ###   ########.fr       */
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
