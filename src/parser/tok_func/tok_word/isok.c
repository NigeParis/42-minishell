/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:56:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "parser_types.h"

#include <stdbool.h>

bool	isok_word(const char *line, t_preparser_context *ctx)
{
	if (ctx->quote_ctx == QUOTE_SQUOTE)
		return (true);
	if (ft_isascii(*line))
		return (true);
	return (false);
}
