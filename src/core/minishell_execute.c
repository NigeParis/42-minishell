/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 19:53:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

void	print_redirs(t_list *redirs)
{
	t_list	*node;
	t_redir	*redir;

	node = redirs;
	dprintf(2, "redirs:\n");
	while (node)
	{
		redir = node->data;
		dprintf(2, "\t\t");
		if (redir->flag == RDIR_STD)
			dprintf(2, "%d", redir->src_std);
		else
			dprintf(2, "%s", redir->src_file);
		if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT
		&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			dprintf(2, " << ");
		else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
			dprintf(2, " < ");
		else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT
		&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			dprintf(2, " >> ");
		else
			dprintf(2, " | ");
		if (redir->target_file)
			dprintf(2, "%s", redir->target_file);
		else
			dprintf(2, "%d", redir->target_std);
		dprintf(2, "\n");
		node = node->next;
	}
	dprintf(2, "\n\n");
}

void	print_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;

	if (cmd == NULL)
	{
		dprintf(2, "cmd is NULL\n");
		return ;
	}
	dprintf(2, "cmd %s\t", cmd->cmd_path);
	dprintf(2, "\tac: %d\n", cmd->ac);
	i = 0;
	while (cmd->argv[i])
		dprintf(2, "[%zu] %s\n", i, cmd->argv[i]), i++;
	dprintf(2, "\t--\tend of args\n");
	i = 0;
	while (cmd->env[i] && i < 5)
		dprintf(2, "[%zu] %s\n", i, cmd->env[i]), i++;
	if (cmd->env[i])
		dprintf(2, "\t--\trest of env ommited from log...\n");
	print_redirs(cmd->redir_to_do);
}

static void free_rdr_node(void *abst_node)
{
	t_redir	*redir;

	redir = abst_node;
	if (redir->target_file)
		free(redir->target_file);
	if (redir->src_file)
		free(redir->src_file);
	free(redir);
}

void discard_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;
	char	*nd;

	if (cmd == NULL)
		return ((void) dprintf(2, "error on error::cmd is NULL\n"));
	if (cmd->argv)
		ft_free_2d((void **)cmd->argv), cmd->argv = NULL;
	if (cmd->env)
		ft_free_2d((void **)cmd->env), cmd->env = NULL;
	if (cmd->redir_to_do)
		ft_ll_clear(&cmd->redir_to_do, free_rdr_node);
	if (cmd->construction_vector)
	{
		ft_vec_apply(cmd->construction_vector, free);
		ft_vec_destroy(&cmd->construction_vector);
	}
	cmd->redir_to_do = NULL;
	free(cmd->cmd_path);
	free(cmd);
}

int (*get_builtin(const char *cmd))(t_minishell_control *, t_cmd_to_exec *)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (&cd_main);
	if (ft_strcmp(cmd, "env") == 0)
		return (&env_main);
	if (ft_strcmp(cmd, "exit") == 0)
		return (&exit_main);
	if (ft_strcmp(cmd, "echo") == 0)
		return (&echo_main);	
	if (ft_strcmp(cmd, "export") == 0)
		return (&export_main);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (&pwd_main);
	if (ft_strcmp(cmd, "unset") == 0)
		return (&unset_main);
	return (NULL);
}

static void exec_cl(t_minishell_control *shell);
static int	do_rdr(t_redir *rdr)
{
	int fd;
	int op_mode;

	fd = -1;
	op_mode = 0;
	if ((rdr->redir_type & RDIR_MSK_IO) == RDIR_PIPE)
		return (EXIT_SUCCESS);
	if ((rdr->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		op_mode = O_RDONLY;
	else if ((rdr->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT)
		op_mode = O_WRONLY | O_CREAT;
	if ((rdr->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
		op_mode |= O_APPEND;
	else
		op_mode |= O_TRUNC;
	if (rdr->target_file)
		fd = open(rdr->target_file, op_mode, 0644);
	else
		fd = rdr->target_std;
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		perror(rdr->target_file);
		return (EXIT_FAILURE);
	}
	if ((rdr->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		dup2(fd, rdr->src_std);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

static int do_rdr_list(t_list *rdr_lst)
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

static void child_exec(t_minishell_control *shell, t_cmd_to_exec *cmd, int *p_fd, int *pp_fd)
{
	if (cmd->cmd_path == NULL)
	{
		printf("%s: %s: command not found\n", ft_progname(), cmd->argv[0]);
		if (pp_fd[0] != -1 || pp_fd[1] != -1)
			(close(pp_fd[0]), close(pp_fd[1]));
		if (p_fd[0] != -1 || p_fd[1] != -1)
			(close(p_fd[0]), close(p_fd[1]));
		discard_cmd(cmd), exec_cl(shell), minishell_cleanup(shell), exit(127);
	}
	if (pp_fd[0] != -1)
		(dup2(pp_fd[0], STDIN_FILENO), close(pp_fd[0]), close(pp_fd[1]));
	if (p_fd[STDOUT_FILENO] != -1)
		(dup2(p_fd[1], STDOUT_FILENO), close(p_fd[1]), close(p_fd[0]));
	if (cmd->redir_to_do && do_rdr_list(cmd->redir_to_do) == EXIT_FAILURE)
	{
		discard_cmd(cmd);
		minishell_cleanup(shell);
		exit(1);
	}
	ft_ll_clear(&cmd->redir_to_do, free_rdr_node);
	execve(cmd->cmd_path, cmd->argv, cmd->env);
	discard_cmd(cmd);
	minishell_cleanup(shell);
	perror("execve");
	exit(126);
}

void	signal_init(void);

static void parent_exec(t_minishell_control *shell, t_cmd_to_exec *cmd, int pid, int *prev_pipe)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (prev_pipe[1] != -1 || prev_pipe[0] != -1)
		(close(prev_pipe[0]), close(prev_pipe[1]));
	waitpid(pid, &cmd->status, 0);
	if (WIFSIGNALED(cmd->status))
	{
		dprintf(2,"child process killed by signal %d\n", WTERMSIG(cmd->status));
		shell->exit = 128 + WTERMSIG(cmd->status);
		dprintf(2, "%s : %d %s %s\n", ft_progname(), pid,
		strsignal(WTERMSIG(cmd->status)), cmd->argv[0]);
	}
	else
		shell->exit = WEXITSTATUS(cmd->status);
	if (DEBUG_LVL >= 10)
		dprintf(2, "cmd status: %d\n", cmd->status);
	if (DEBUG_LVL >= 20)
		print_cmd(cmd);
	discard_cmd(cmd);
	signal_init();
}

static void exec_cl(t_minishell_control *shell)
{
	t_preparsed_node *node;
	size_t i;

	if (!shell)
		return ;
	i = 0;
	if (shell->preparsed)
	{

		while (i < shell->preparsed->count)
		{
			node = ft_vec_at(shell->preparsed, i);
			if (node && node->destroy)
				node->destroy(node);
			i++;
		}
		ft_vec_destroy(&shell->preparsed);
		shell->preparsed = NULL;
	}
}

static void b_in(t_minishell_control *shell, t_cmd_to_exec *cmd)
{
	int				(*builtin)(t_minishell_control *, t_cmd_to_exec *);

	dprintf(2, "builtin: %s detected\n", cmd->argv[0]);
	builtin = get_builtin(cmd->argv[0]);
	builtin(shell, cmd);
	shell->exit = cmd->status;
	discard_cmd(cmd);
}

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

static void set_pipe(int *pipe_fd, int fd_1, int fd_2)
{
	pipe_fd[0] = fd_1;
	pipe_fd[1] = fd_2;
}

int	minishell_execute(t_minishell_control *shell)
{
	t_cmd_to_exec	*cmd;
	int				pid;
	int				status;
	int				pp_fd[2];
	int				p_fd[2];

	(set_pipe(pp_fd, -1, -1), set_pipe(p_fd, -1, -1));
	cmd = parser_get_cmd(shell->preparsed, shell);
	status = 0;
	while (cmd && (status == 0 || status == 127))
	{
		dprintf(STDERR_FILENO, "%p : cmd\t rdir ? %s\n", cmd, cmd->redir_to_do ? "yes" : "no");
		set_pipe(p_fd, -1, -1);
		if (cmd->redir_to_do && has_pipe(cmd->redir_to_do) && pipe(p_fd) != -1)
			perror("pipe"); // todo : do better
		if (cmd && cmd->ac >= 1 && get_builtin(cmd->argv[0]))
		{
			cmd = (b_in(shell, cmd), parser_get_cmd(shell->preparsed, shell));
			continue ;
		}
		pid = fork();
		if (pid == -1)
			return (perror("fork"), exec_cl(shell), EXIT_FAILURE);
		if (pid == 0)
			child_exec(shell, cmd, p_fd, (int *)pp_fd);
		else // parent
			parent_exec(shell, cmd, pid, pp_fd);
		(set_pipe(pp_fd, p_fd[0], p_fd[1]), set_pipe(p_fd, -1, -1));
		status = shell->exit;
		cmd = parser_get_cmd(shell->preparsed, shell);
	}
	if (cmd && status != 0)
		discard_cmd(cmd);
	if (pp_fd[0] != -1 || pp_fd[1] != -1)
		(close(pp_fd[0]), close(pp_fd[1]));
	return (exec_cl(shell), EXIT_SUCCESS);
}
