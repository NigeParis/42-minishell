/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_varexpansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:27:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 14:28:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

bool	tok_val_varexpansion(char *s, t_parser *parser)
{
	if (*s != '$')
		return (false);
	if (parser->quote == QUOTE_NONE || parser->quote == QUOTE_DOUBLE)
		return (true);
	return (false);
}
