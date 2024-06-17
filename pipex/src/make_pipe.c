/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/17 14:22:11 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int make_pipe(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	int ret;
	// int     status = 0;

	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");
	pipex->child_pid = fork();
	if (pipex->child_pid == -1)
		perror("fork");
	if (!pipex->child_pid)
	{
		child_process(pipex, args, redir, i);
	}
	else
	{
		parent_process(pipex, redir);
	}
	return (0);
}

void child_process(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	(void)i;

	if (args->lastcmd_index == FIRST_CMD)
	{
		dprintf(STDERR_FILENO, "first %s%s\n", args->argv[0], args->argv[1]);
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		if (redir->src_flag)
		{
			dup2(pipex->fdin, STDIN_FILENO);
			close_fd(&pipex->fdin);
		}
	}
	else if (args->lastcmd_index == PIPE_CMD)
	{
		dprintf(STDERR_FILENO, "second %s%s\n", args->argv[0], args->argv[1]);

		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (args->lastcmd_index == LAST_CMD)
	{
		dprintf(STDERR_FILENO, "last %s %s\n", args->argv[0], args->argv[1]);

		if (redir->dst_flag)
		{
			dup2(pipex->fdout, STDOUT_FILENO);
			close_fd(&pipex->fdout);
		}
	}
	// close(pipex->pipe_fd[1]);
	// close(pipex->pipe_fd[0]);
	dprintf(STDERR_FILENO, "executed %s\n\n", args->argv[0]);

	exec_cmd(args, pipex, redir);
}

void parent_process(t_pipex *pipex, t_redir *redir)
{
	(void)redir;
	(void)pipex;
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
}

void ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{

	make_pipe(pipex, args, redir, i);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}

/*
int	make_pipe(t_pipex *pipex, char *env[], char *argv[], int i)
{
	pid_t	process;
	int		ret;

	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");
	process = fork();
	if (process == -1)
		perror("fork");
	if (!process)
	{
		child_process(pipex, argv, env, i);
	}
	else
	{
		parent_process(pipex);
	}
	return (0);
}

void	child_process(t_pipex *pipex, char *argv[], char *env[], int i)
{
	close(pipex->pipe_fd[0]);
	if (i == 2 && pipex->doc == 0)
		dup2(pipex->fdin, STDIN_FILENO);
	if (i == 3 && pipex->doc == 1)
	{
		dup2(pipex->pipe_doc[0], STDIN_FILENO);
	}
	if (i == pipex->nb_argc - 2)
	{
		dup2(pipex->fdout, STDOUT_FILENO);
		close_fd(pipex, 1);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
	}
	if (pipex->doc == 1)
		close(pipex->pipe_doc[0]);
	close(pipex->fdout);
	close_fd(pipex, 10);
	close(pipex->pipe_fd[1]);
	get_path_absolu(pipex, argv, i);
	exec_cmd(pipex, i, argv, env);
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
}

void	ft_pipes(t_pipex *pipex, char *argv[], char *env[], int i)
{
	make_pipe(pipex, env, argv, i);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	ft_cleanup(pipex, 8);
}
*/