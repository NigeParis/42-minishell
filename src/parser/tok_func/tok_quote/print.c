/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:34:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_funcs.h"
#include "parser_types.h"

#include <stdio.h>

void	prepn_quote_print(t_preparsed_node *node)
{
	t_quote_node	*quote;
	const char		*qt_type[3] = {"NONE", "SQUOTE", "DQUOTE"};

	quote = node->value;
	printf("%s", qt_type[quote->type]);
	if (quote->value)
		printf("('%s')", quote->value->str);
	else
		printf("(none)");
	printf("\t");
}
