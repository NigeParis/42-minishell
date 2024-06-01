/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:19:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 09:27:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdbool.h>

bool	tok_val_quote(const char *str, t_parser *parser)
{
	if (str[0] != '\'' && str[0] != '"')
		return (false);
	if ((parser->quote == QUOTE_NONE) ||
	(parser->quote == QUOTE_SINGLE && str[0] == '\'') ||
	(parser->quote == QUOTE_DOUBLE && str[0] == '"'))
		return (true);
	return (false);
}
