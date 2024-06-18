/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 15:00:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include <stdio.h>
#include <sys/wait.h>

void	print_cmd(t_cmd *cmd)
{
	size_t	i;

	printf("cmd %s\t", cmd->cmd);
	printf("\tac: %d\n", cmd->argc);
	i = 0;
	while (cmd->args[i])
		printf("[%zu] %s\n", i, cmd->args[i]), i++;
	printf("\t--\tend of args\n");
	i = 0;
	while (cmd->envp[i] && i < 5)
		printf("[%zu] %s\n", i, cmd->envp[i]), i++;
	if (cmd->envp[i])
		printf("\t--\trest of env ommited from log...\n\n");
}

void discard_cmd(t_cmd_to_exec *cmd)
{
	size_t i;

	i = 0;
	while (cmd->argv[i])
		free(cmd->argv[i]), i++;
	free(cmd->argv);
	i = 0;
	while (cmd->env[i])
		free(cmd->env[i]), i++;
	free(cmd->env);
	free(cmd->cmd_path);
	free(cmd);
}

int	minishell_execute(t_minishell_control *shell)
{
	t_cmd_to_exec	*cmd;
	size_t	i;

	shell->exit = 0;
	cmd = parser_get_cmd(shell->preparsed, shell);
	printf("dbg:: prepn -> %p\n", shell->preparsed);
	while (cmd && shell->exit == 0)
	{
		int pid = fork();
		if (pid == 0)
		{
			if (cmd->cmd_path == NULL)
				printf("%s: %s: command not found\n", ft_progname(), cmd->argv[0]),
				discard_cmd(cmd),
				minishell_cleanup(shell),
				exit(127);
			execve(cmd->cmd_path, cmd->argv, cmd->env);
			discard_cmd(cmd);
			minishell_cleanup(shell);
			perror("execve");
			exit(126);
		}
		else
		{
			waitpid(pid, NULL, 0);
			cmd->status = WEXITSTATUS(pid);
		}
		shell->exit = cmd->status;
		discard_cmd(cmd);
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	return (0);
}
