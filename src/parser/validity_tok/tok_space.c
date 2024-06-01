/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:22:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 09:28:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include "ft_string.h"
#include <stdbool.h>

bool	tok_val_space(const char *s, t_parser *parser)
{
	if (!ft_isspace(*s))
		return (false);
	if (ft_isspace(*s) && parser->quote == QUOTE_NONE)
		return (true);
	return (false);
}
