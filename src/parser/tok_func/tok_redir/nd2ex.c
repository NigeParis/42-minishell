/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 00:14:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser_types.h"
#include <stdbool.h>
#include <stdio.h>

bool	nd2ex_redir(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	t_redir *rdr;
	t_preparsed_node *nd_next;

	nd_next = ft_vec_at(sh->preparsed, cmd->nb_tok_consumed);
	if (nd_next->type != TOK_WORD && nd_next->type != TOK_QUOTE)
		return (
		printf("unexpected token after '>'\n"),
		false);
	rdr = nd->value;
	rdr->target_file = nd_next->value;
	return (false);
}

