/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:22:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:29:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_types.h"
#include "parser_types.h"

bool has_pipe(t_list *redirs)
{
	t_list	*node;
	t_redir	*redir;

	node = redirs;
	while (node)
	{
		redir = node->data;
		if (redir->redir_type == RDIR_PIPE)
			return (true);
		node = node->next;
	}
	return (false);
}

void set_pipe(int *pipe_fd, int fd_1, int fd_2)
{
	pipe_fd[0] = fd_1;
	pipe_fd[1] = fd_2;
}
