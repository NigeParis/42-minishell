/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 12:42:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_args.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

// leaks everywhere --- in dev | todo: fix leaks
//		return (printf("ambiguous redirect\n"), false);	//	actual bash error 
//															message do not 
//															remove

static void	perr_rdr(char *msg)
{
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
}

static void	catastrophe_quit(t_preparsed_node *nd_next, t_cmd_to_exec *cmd,
		int consumed, t_minishell_control *sh)
{
	nd_next->destroy(nd_next);
	ft_vec_shift(sh->preparsed, cmd->nb_tok_consumed, consumed
		- cmd->nb_tok_consumed);
}

bool	get_target(t_minishell_control *sh, int consumed, t_cmd_to_exec *cmd,
				char **str_c)
{
	t_preparsed_node	*nd_next;
	t_quote_node		*quote;
	t_string			*str;

	nd_next = ft_vec_at(sh->preparsed, consumed++);
	if (nd_next && nd_next->type == TOK_SPACE)
		nd_next = (nd_next->destroy(nd_next), ft_vec_at(sh->preparsed, \
					consumed++));
	if (!nd_next || (nd_next->type != TOK_WORD && nd_next->type != TOK_QUOTE))
		return (catastrophe_quit(nd_next, cmd, consumed, sh), \
		perr_rdr("unexpected token after redirection\n"), false);
	if (nd_next->type == TOK_QUOTE)
	{
		quote = nd_next->value;
		str = quote->value;
		if (quote->type == QUOTE_DQUOTE && resolve_word(&str, sh) == false)
			return (catastrophe_quit(nd_next, cmd, consumed, sh), false);
		free(quote);
	}
	else
		str = nd_next->value;
	*str_c = ft_string_to_str_inplace(&str);
	return (free(nd_next), ft_vec_shift(sh->preparsed, cmd->nb_tok_consumed, \
	consumed - cmd->nb_tok_consumed), true);
}

bool	nd2ex_redir(t_preparsed_node *nd, t_cmd_to_exec *cmd,
		t_minishell_control *sh)
{
	t_redir				*rdr;
	char				*str_c;
	t_string			*str;
	t_quote_node		*quote;

	rdr = nd->value;
	if (rdr->redir_type & RDIR_MSK_DUP && rdr->target_std != -1)
		return (ft_ll_push_back(&cmd->redir_to_do, nd->value), \
		free(nd), true);
	if (get_target(sh, cmd->nb_tok_consumed, cmd, &str_c) == false)
		return (false);
	if (ft_strchr(str_c, '$'))
		return (perr_rdr("ambiguous redirect\n"), false);
	rdr->target_file = str_c;
	if (rdr->redir_type & RDIR_MSK_DUP)
	{
		if (ft_str_isdigit(rdr->target_file) == false)
			return (perr_rdr("bad file descriptor\n"), free(str_c), false);
		rdr->target_std = ft_atoi(str_c);
		rdr->target_file = NULL;
	}
	ft_ll_push_back(&cmd->redir_to_do, rdr);
	return (free(nd), true);
}
