/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:53:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_addons.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include "ft_debug.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

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

static int get_op_mode(int type)
{
	int op_mode;

	op_mode = 0;
	if ((type & RDIR_MSK_IO) == RDIR_PIPE)
		return (EXIT_SUCCESS);
	if ((type & RDIR_MSK_IO) == RDIR_INPUT)
		op_mode = O_RDONLY;
	else if ((type & RDIR_MSK_IO) == RDIR_OUTPUT)
	op_mode = O_WRONLY | O_CREAT;
	if ((type & RDIR_MSK_MODE) == RDIR_APPEND)
		op_mode |= O_APPEND;
	else
		op_mode |= O_TRUNC * (type & RDIR_MSK_IO) == RDIR_OUTPUT;
	return (op_mode);
}

static int	do_rdr(t_redir *rdr)
{
	int t_fd;
	int s_fd;
	int op_mode;

	if (rdr->redir_type == RDIR_PIPE)
		return (EXIT_SUCCESS);
	t_fd = rdr->target_std;
	op_mode = get_op_mode(rdr->redir_type);
	if (rdr->target_file)
		t_fd = open(rdr->target_file, op_mode, 0644);
	if (t_fd == -1)
		return (ft_putstr_fd("minishell: ", STDERR_FILENO), 
			perror(rdr->target_file), EXIT_FAILURE);
	s_fd = rdr->src_std;
	if (rdr->src_file)
		s_fd = open(rdr->src_file, O_WRONLY);
	if (s_fd == -1)
	{
		if (t_fd > 2)
			close(t_fd);
		return (ft_putstr_fd("minishell: ", STDERR_FILENO), 
			perror(rdr->src_file), EXIT_FAILURE);
	}
	if (dup2(t_fd, s_fd) == -1)
	{
		perror("dup2");
		close(t_fd);
		close(s_fd);
		return (EXIT_FAILURE);
	}
	close(t_fd);
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
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
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

static void parent_exec(t_minishell_control *shell, t_cmd_to_exec *cmd, int pid, int *prev_pipe)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (prev_pipe[1] != -1 || prev_pipe[0] != -1)
		(close(prev_pipe[0]), close(prev_pipe[1]));
	waitpid(pid, &cmd->status, 0);
	if (WIFSIGNALED(cmd->status))
	{
		shell->exit = 128 + WTERMSIG(cmd->status);
		dprintf(2, "%s : %d %s %s", ft_progname(), pid,
		ft_strsignal(WTERMSIG(cmd->status)), cmd->argv[0]);
		if (WCOREDUMP(cmd->status))
			printf("(core dumped)");
		printf("\n");
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


static void b_in(t_minishell_control *shell, t_cmd_to_exec *cmd)
{
	int				(*builtin)(t_minishell_control *, t_cmd_to_exec *);

	dprintf(2, "builtin: %s detected\n", cmd->argv[0]);
	builtin = get_builtin(cmd->argv[0]);
	builtin(shell, cmd);
	shell->exit = cmd->status;
	discard_cmd(cmd);
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
		set_pipe(p_fd, -1, -1);
		if (cmd->redir_to_do && has_pipe(cmd->redir_to_do) && pipe(p_fd) == -1)
			perror("pipe"); // todo : do better aka clean up and return
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
