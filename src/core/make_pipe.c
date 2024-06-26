/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/26 15:10:16 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <signal.h>

int make_pipe(t_pipex *pipex, t_cmd_to_exec *argv)
{
	int ret;
	dprintf(STDERR_FILENO, "MakePipes\n");
	
	if (!argv->status)
	{
		signal(SIGQUIT, backslash_handler);
    	signal(SIGINT, Ctrl_C_child_handler);   /* Ctrl-c handler*/

	}

	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");

	pipex->child_pid = fork();
	if (pipex->child_pid == -1)
		perror("fork");
	
	if (!pipex->child_pid)
	{
		child_process(pipex, argv);
	}
	else
	{	
		parent_process(pipex, argv);
	}
	return (0);
}






void child_process(t_pipex *pipex, t_cmd_to_exec *argv)
{
	t_redir *redir = NULL;

	dprintf(STDERR_FILENO, "Child_process\n");

	// redir = (t_redir*)argv->redir_to_do->data;	  // crash here argv->redir-to->data absent ?
	redir = test_redir_ls();	  // crash here argv->redir-to->data absent ?
	close(pipex->pipe_fd[0]);
	if (redir->flag == RDIR_FILE  && redir->redir_type == 0)
	{
		dprintf(STDERR_FILENO, "Inside_ch_first\n");
		
		ft_open_file(pipex, argv);
		dup2(pipex->fdin, STDIN_FILENO);
		close_fd(&pipex->fdin);
	}
	else if (redir->redir_type == RDIR_PIPE)
	{
		dprintf(STDERR_FILENO, "Inside_ch_second\n");
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (redir->flag == RDIR_FILE \
			&& (redir->redir_type == RDIR_TRUNC \
			|| redir->redir_type == RDIR_APPEND))
	{
			dprintf(STDERR_FILENO, "Inside_ch_last\n");
			ft_open_file(pipex, argv);
			dup2(pipex->fdout, STDOUT_FILENO);
			close_fd(&pipex->fdout);
	}
	close(pipex->pipe_fd[1]);
	
	dprintf(STDERR_FILENO, "Exec_cmd_call\n");
	exec_cmd(argv, pipex);
}

void parent_process(t_pipex *pipex, t_cmd_to_exec *argv)
{
	(void)pipex;
	(void)argv;
	dprintf(STDERR_FILENO, "Parent_process\n");
	

	
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
		
	//if (argv->lastcmd_index == LAST_CMD)
	waitpid(pipex->child_pid, &argv->status, 0);
	
}


