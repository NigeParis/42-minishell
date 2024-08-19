/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 09:24:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

#include <stdio.h>
#include <unistd.h>

void	prepn_redir_print(t_preparsed_node *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->value;
	printf("REDIR: ");
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		printf("INPUT ");
	else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT)
		printf("OUTPUT ");
	else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_PIPE)
		printf("PIPE ");
	if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
		printf("APPEND ");
	else if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_TRUNC)
		printf("TRUNC ");
	else if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_HEREDOC)
		printf("HEREDOC ");
	printf("on ");
	if (redir->target_file)
		printf("file: %s", redir->target_file);
	else
		printf("fd: %d", redir->target_std);
	printf("\t");
}
