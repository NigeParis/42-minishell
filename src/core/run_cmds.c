/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/27 12:45:52 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"





void	exec_cmd(t_cmd_to_exec *argv, t_pipex *pipex, t_minishell_control *shell)
{
	int	ret;
	int	(*builtin)(t_minishell_control *, t_cmd_to_exec *);


	ret = -1;
	(void)pipex;
	
		dprintf(STDERR_FILENO, "argv[0]------> %s\n", argv->argv[0]);

		if ((ft_strcmp(argv->argv[0], "cd") == 0) ||
			(ft_strcmp(argv->argv[0], "echo") == 0) ||
			(ft_strcmp(argv->argv[0], "env") == 0) ||
			(ft_strcmp(argv->argv[0], "pwd") == 0) ||
			(ft_strcmp(argv->argv[0], "export") == 0) ||
			(ft_strcmp(argv->argv[0], "unset") == 0))
		{
			argv->cmd_path = NULL;
		}
		
		dprintf(STDERR_FILENO, "argv cmd path %s\n", argv->cmd_path);
		
		if (argv && !argv->cmd_path && argv->ac >= 1 && get_builtin(argv->argv[0]))
		{
			printf("builtin: %s detected\n", argv->argv[0]);
			// run builtin here
			builtin = get_builtin(argv->argv[0]);
			builtin(shell, argv);
			discard_cmd(argv);
			//argv = parser_get_cmd(shell->preparsed, shell);
			exit (0);
		}


		if (argv->cmd_path == NULL)
		{
				printf("%s: %s: command not found\n", ft_progname(), argv->argv[0]),
				discard_cmd(argv),
				minishell_cleanup(shell),
				exit(127);
		}

		
	
		close_fd(&pipex->fdin);
		close_fd(&pipex->fdout);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);

		
		ret = execve(argv->cmd_path, argv->argv, argv->env);
		if (ret == -1)
		{
			discard_cmd(argv);
			minishell_cleanup(shell);
			perror("execve");
			exit(126);
		}
		
}

