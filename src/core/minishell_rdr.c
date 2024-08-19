/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_rdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:07:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 09:37:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_args.h"
#include "ft_string.h"
#include "parser_types.h"
#include "minishell.h"

#include <fcntl.h>
#include <unistd.h>

static void	perr_rdr(char *file)
{
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_perror(file);
}

static int	do_classic_rdr(t_redir *rdr)
{
	int	t_fd;
	int	s_fd;
	int	op_mode;

	op_mode = get_op_mode(rdr->redir_type);
	t_fd = rdr->target_std;
	if (rdr->target_file)
		t_fd = open(rdr->target_file, op_mode, 0644);
	if (t_fd == -1)
		return (perr_rdr(rdr->target_file), EXIT_FAILURE);
	s_fd = rdr->src_std;
	if (rdr->src_file)
		s_fd = open(rdr->src_file, O_WRONLY);
	if (s_fd == -1)
	{
		if (t_fd > 2)
			close(t_fd);
		return (ft_putstr_fd(ft_progname(), STDERR_FILENO), \
			ft_putstr_fd(": ", STDERR_FILENO), \
			ft_perror(rdr->src_file), EXIT_FAILURE);
	}
	if (dup2(t_fd, s_fd) == -1)
		return (ft_perror("dup2"), close(t_fd), close(s_fd), EXIT_FAILURE);
	return (close(t_fd), EXIT_SUCCESS);
}

static int	do_rdr(t_redir *rdr)
{
	if (rdr->redir_type == RDIR_PIPE || rdr->redir_type == RDIR_HEREDOC)
		return (EXIT_SUCCESS);
	return (do_classic_rdr(rdr));
}

int	do_rdr_list(t_list *rdr_lst)
{
	t_list	*node;

	node = rdr_lst;
	while (node)
	{
		if (do_rdr(node->data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
