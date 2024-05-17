/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:19:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 14:42:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "parser_types.h"

// if no quote set quote
// if quote is set and quote match set quote to none
// else append char to word
void	token_quote_all_handler(const char *str, t_parser *prs, t_vector *env)
{
	if (prs->quote == QUOTE_NONE)
	{
		if (str[0] == '"')
			prs->quote = QUOTE_DOUBLE;
		else
			prs->quote = QUOTE_SINGLE;
		return ;
	}
	if ((prs->quote == QUOTE_SINGLE && str[0] == '\'') || \
	(prs->quote == QUOTE_DOUBLE && str[0] == '"'))
		return (prs->quote = QUOTE_NONE, (void)0);
	ft_strappend_c((char **)&prs->words->datas[prs->word_offset], str[0]);
}
