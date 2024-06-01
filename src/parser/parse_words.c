/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:22:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:43:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_vector *preparse_cmds(const char *str, t_parser *restrict parser)
{
	return (NULL);
}
