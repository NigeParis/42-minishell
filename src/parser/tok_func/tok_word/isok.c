/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 16:39:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_char.h"
#include "parser_types.h"

bool isok_word(const char *line, t_preparser_context *ctx)
{
	if (ctx->quote_ctx == QUOTE_SQUOTE)
		return (true);
	if (ft_isprint(*line) && !ft_isspace(*line) && *line != '\0')
		return (true);
	return (false);
}
