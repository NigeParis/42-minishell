/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 09:57:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"

void	parser_cleanup(t_parser *prs)
{
	if (prs->words)
		ft_free((void **)&prs->words);
}

void	parser_cleanup_final(t_parser *prs)
{
	parser_cleanup(prs);
	if (prs->tokens_handlers)
		ft_vec_destroy(&prs->tokens_handlers);
}
