/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_varexpansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:27:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 09:29:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

bool	tok_val_doll(const char *s, t_parser *parser)
{
	if (*s != '$' || parser->quote == QUOTE_SINGLE)
		return (false);
	if (parser->quote == QUOTE_NONE || parser->quote == QUOTE_DOUBLE)
		return (true);
	return (false);
}
