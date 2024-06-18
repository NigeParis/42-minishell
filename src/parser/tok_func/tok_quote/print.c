/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 12:47:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_funcs.h"
#include "parser_types.h"
#include <stdio.h>

void	prepn_quote_print(t_preparsed_node *node)
{
	t_quote_node	*quote;

	quote = node->value;
	printf("%s('%s')\t", quote->type == QUOTE_SQUOTE ? "SQUOTE" : "DQUOTE", quote->value->str);
}
