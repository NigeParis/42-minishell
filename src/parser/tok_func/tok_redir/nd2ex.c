/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 12:55:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"
#include <stdbool.h>
#include <stdio.h>

void discard_cmd(t_cmd_to_exec *cmd);
bool	resolve_word(t_string **word, t_minishell_control *sh);

// leaks everywhere --- in dev | todo: fix leaks
bool	nd2ex_redir(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	t_redir *rdr;
	char *str_c;
	t_string *str;
	t_preparsed_node *nd_next;
	t_quote_node *quote;
	size_t consumed;

	consumed = cmd->nb_tok_consumed;
	nd_next = ft_vec_at(sh->preparsed, consumed++);
	if (nd_next && nd_next->type == TOK_SPACE)
	{
		nd_next->destroy(nd_next);
		nd_next = ft_vec_at(sh->preparsed, consumed++);
	}
	if (nd_next && nd_next->type != TOK_WORD && nd_next->type != TOK_QUOTE)
		return (printf("unexpected token after '>'\n"), false);
	if (nd_next->type == TOK_QUOTE)
	{
		quote = nd_next->value;
		str = quote->value;
		if (quote->type == QUOTE_DQUOTE	&& resolve_word(&str, sh) == false)
			return (false);
		str_c = ft_string_to_str_inplace(str);
		free(quote);
	}
	else
	{
		str = nd_next->value;
		str_c = ft_string_to_str_inplace(str);
	}
	free(nd_next);
	if (ft_strchr(str_c, '$'))
	{
		printf("ambiguous redirect\n"); // actual bash error message do not remove
		return (false);
	}
	ft_vec_shift(sh->preparsed, cmd->nb_tok_consumed, consumed - cmd->nb_tok_consumed);
	rdr = nd->value;
	rdr->target_file = str_c;
	return (false);
}

