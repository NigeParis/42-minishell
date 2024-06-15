/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 16:19:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_funcs.h"
#include "parser_types.h"
#include <stdio.h>

void	prepn_quote_print(t_preparsed_node *node)
{
	printf("Quote (%s)\t", (int)((long)node->value) == QUOTE_NONE ?
	"None" : (int)((long)node->value) == QUOTE_SQUOTE ? "Single" : "Double");
}
