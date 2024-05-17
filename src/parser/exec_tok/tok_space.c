/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:19:22 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:19:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	token_space_handler(const char *str, t_parser *prs)
{
	if (prs->str_offset > 0 && prs->quote == QUOTE_NONE && str[-1] != ' ')
		prs->word_offset++;
	else
		bulk_add_char(prs, str, 1);
}
