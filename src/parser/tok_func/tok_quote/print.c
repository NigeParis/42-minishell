/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 14:33:56 by bgoulard         ###   ########.fr       */
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
	printf("%s('%s')\t", qt_type[quote->type], quote->value->str);
}
