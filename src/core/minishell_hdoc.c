/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_hdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:22:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 09:35:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_args.h"
#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"

bool	has_heredoc(t_list *rdr_lst)
{
	t_list	*node;

	node = rdr_lst;
	while (node)
	{
		if (((t_redir *)node->data)->redir_type == RDIR_HEREDOC)
			return (true);
		node = node->next;
	}
	return (false);
}

static void	print_heredoc_err(char *target)
{
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(": unexpected EOF while looking for matching heredoc string" \
	" `", STDERR_FILENO);
	ft_putstr_fd(target, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}

static int	here_dod_pipes(char *line, t_string *buf, int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		return (ft_perror("pipe"), ft_string_destroy(&buf), EXIT_FAILURE);
	write(pipe_fd[1], buf->str, buf->length);
	ft_string_destroy(&buf);
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (ft_perror("dup2"), close(pipe_fd[0]), EXIT_FAILURE);
	close(pipe_fd[0]);
	free(line);
	return (EXIT_SUCCESS);
}

int	do_heredoc(t_redir *rdr, bool integrated_pipes)
{
	char		*line;
	t_string	*buf;
	int			pipe_fd[2];

	ft_putstr_fd("hdoc >", STDOUT_FILENO);
	buf = ft_string_new(1);
	line = get_next_line(STDIN_FILENO);
	while (line && (line[0] == '\n' || ft_strncmp(line, rdr->target_file,
				ft_strlen(line) - 1)))
	{
		ft_string_append(buf, line);
		free(line);
		ft_putstr_fd("hdoc >", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
	}
	if (!line)
		return (print_heredoc_err(rdr->target_file), ft_string_destroy(&buf),
			EXIT_FAILURE);
	if (integrated_pipes)
		return (here_dod_pipes(line, buf, pipe_fd));
	return (ft_string_destroy(&buf), free(line), EXIT_SUCCESS);
}

void	do_hdoc_cmd(t_cmd_to_exec *cmd, t_minishell_control *shell)
{
	t_list	*node;

	node = cmd->redir_to_do;
	while (node && ((t_redir *)node->data)->redir_type != RDIR_HEREDOC)
		node = node->next;
	if (do_heredoc(node->data, true) == EXIT_FAILURE)
		dd_cl(cmd, shell, 1);
}
