/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 10:14:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdio.h>
#include <unistd.h>

void	prepn_redir_print(t_preparsed_node *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->value;
	printf("redirection (f:%s (if std %d else %s), on %s using mode : %s%s%s) to %s\n",
		 redir->flag == RDIR_STD ?
			"RDIR_STD" : // yes branch of condition
			"RDIR_FILE", // no branch of condition
		redir->flag == RDIR_STD ?
			redir->src_std : // yes branch of condition
			-1, // no branch of condition
		redir->flag == RDIR_STD ?
			NULL : // yes branch of condition
			redir->src_file, // no branch of condition
		(redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT ?
			"INPUT" // yes branch of condition
			: (redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT ?
				"OUTPUT" // yes branch of condition
				:"PIPE", // no branch of condition
		(redir->redir_type & RDIR_MSK_MODE) == RDIR_TRUNC ? 
			"TRUNC" // yes branch of condition
			: "", // no branch of condition
		(redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND ?
			"APPEND" // yes branch of condition
			: "", // no branch of condition
		(redir->redir_type & RDIR_MSK_MODE) == RDIR_DUP ?
			"DUP" // yes branch of condition
			: "", // no branch of condition

		redir->target_file == NULL?
			redir->target_std == STDIN_FILENO ? "STDIN" :
			redir->target_std == STDOUT_FILENO ? "STDOUT" :
			redir->target_std == STDERR_FILENO ? "STDERR" : "UNKNOWN"
		: redir->target_file);
}
