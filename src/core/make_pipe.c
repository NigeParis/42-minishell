/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/29 13:25:00 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <signal.h>
#include <sys/wait.h>


int make_pipe(t_pipex *pipex, t_cmd_to_exec *cmd, t_minishell_control *shell)
{
	int ret;
	
	if (!cmd->status)
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
		child_process(pipex, cmd, shell);
	}
	else
	{	
		parent_process(pipex, cmd, shell);
	}
	return (0);
}






void child_process(t_pipex *pipex, t_cmd_to_exec *cmd, t_minishell_control *shell)
{
	t_redir *redir = NULL;


	//redir = (t_redir*)argv->redir_to_do->data;	  // crash here argv->redir-to->data absent ?
	redir = test_redir_ls();	  // crash here argv->redir-to->data absent ?

	
	close(pipex->pipe_fd[0]);
	if (redir->flag == RDIR_FILE  && redir->redir_type == 0)
	{
		ft_open_file(pipex, cmd);
		dup2(pipex->fdin, STDIN_FILENO);
		close_fd(&pipex->fdin);
	}
	else if (redir->redir_type == RDIR_PIPE)
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (redir->flag == RDIR_FILE \
			&& (redir->redir_type == RDIR_TRUNC \
			|| redir->redir_type == RDIR_APPEND))
	{
			ft_open_file(pipex, cmd);
			dup2(pipex->fdout, STDOUT_FILENO);
			close_fd(&pipex->fdout);
	}
	close(pipex->pipe_fd[1]);
	
	exec_cmd(cmd, pipex, shell);
}

void parent_process(t_pipex *pipex, t_cmd_to_exec *cmd, t_minishell_control *shell)
{
	(void)pipex;
	(void)cmd;
	
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	
	waitpid(pipex->child_pid, &cmd->status, 0);
	shell->exit = WEXITSTATUS(cmd->status);
	if (DEBUG_LVL >= 1)
		printf("cmd status: %d\n", cmd->status);
	if (DEBUG_LVL >= 20)
		print_cmd(cmd);
	discard_cmd(cmd);


 
	//if (argv->lastcmd_index == LAST_CMD)
	
}


