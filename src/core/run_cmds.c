/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/29 11:53:27 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_cmd_to_exec *cmd, t_pipex *pipex, t_minishell_control *shell)
{
	int	ret;
	int	(*builtin)(t_minishell_control *, t_cmd_to_exec *);


	ret = -1;
	(void)pipex;
	
		if ((ft_strcmp(cmd->argv[0], "cd") == 0) ||
			(ft_strcmp(cmd->argv[0], "echo") == 0) ||
			(ft_strcmp(cmd->argv[0], "env") == 0) ||
			(ft_strcmp(cmd->argv[0], "pwd") == 0) ||
			(ft_strcmp(cmd->argv[0], "export") == 0) ||
			(ft_strcmp(cmd->argv[0], "unset") == 0))
		{
			cmd->cmd_path = NULL;
		}
		
		dprintf(STDERR_FILENO, "argv cmd path %s\n", cmd->cmd_path);
		
		if (cmd && !cmd->cmd_path && cmd->ac >= 1 && get_builtin(cmd->argv[0]))
		{
			printf("builtin: %s detected\n", cmd->argv[0]);
			// run builtin here
			builtin = get_builtin(cmd->argv[0]);
			builtin(shell, cmd);
			discard_cmd(cmd);
			//argv = parser_get_cmd(shell->preparsed, shell);
			exit (0);
		}


		if (cmd->cmd_path == NULL)
		{
				printf("%s: %s: command not found\n", ft_progname(), cmd->argv[0]),
				discard_cmd(cmd),
				minishell_cleanup(shell),
				exit(127);
		}

		
	
		close_fd(&pipex->fdin);
		close_fd(&pipex->fdout);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);

		
		ret = execve(cmd->cmd_path, cmd->argv, cmd->env);
		if (ret == -1)
		{
			discard_cmd(cmd);
			minishell_cleanup(shell);
			perror("execve");
			exit(126);
		}
		
}

