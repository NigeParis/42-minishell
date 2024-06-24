/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 13:28:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdio.h>
#include <unistd.h>

void	prepn_redir_print(t_preparsed_node *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->value;
	printf("redirection (%s %s %s)\t", 
		redir->flag == RDIR_STD ?
			redir->src_std == STDIN_FILENO ? "STDIN" : 
			redir->src_std == STDOUT_FILENO ? "STDOUT" : 
			redir->src_std == STDERR_FILENO ? "STDERR" : "UNKNOWN"
		: redir->src_file,
		(redir->flag & RDIR_MSK_IO) == RDIR_OUTPUT ?
			(redir->flag & RDIR_MSK_MODE) == RDIR_APPEND ? ">>" 
			: (redir->flag & RDIR_MSK_MODE) == RDIR_TRUNC ? ">"
			: "UNKNOWN"
		: (redir->flag & RDIR_MSK_IO) == RDIR_INPUT ?
			(redir->flag & RDIR_MSK_MODE) == RDIR_APPEND ? "<<"
			: (redir->flag & RDIR_MSK_MODE) == RDIR_TRUNC ? "<"
			: "UNKNOWN"
		: "UNKNOWN",
		redir->target_file == NULL?
			redir->target_std == STDIN_FILENO ? "STDIN" :
			redir->target_std == STDOUT_FILENO ? "STDOUT" :
			redir->target_std == STDERR_FILENO ? "STDERR" : "UNKNOWN"
		: redir->target_file);
}
