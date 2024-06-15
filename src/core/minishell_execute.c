/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 16:28:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
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

void discard_cmd(t_cmd *cmd)
{
	size_t i;

	i = 0;
	while (cmd->args[i])
		free(cmd->args[i]), i++;
	free(cmd->args);
	i = 0;
	while (cmd->envp[i])
		free(cmd->envp[i]), i++;
	free(cmd->envp);
	free(cmd->cmd);
	free(cmd);
}

int	minishell_execute(t_minishell_control *shell)
{
	t_cmd	*cmd;
	size_t	i;

	shell->exit = 0;
	cmd = parser_get_cmd(shell->preparsed, shell);
	printf("dbg:: prepn -> %p\n", shell->preparsed);
	while (cmd && shell->exit == 0)
	{
		int pid = fork();
		if (pid == 0)
		{
			if (cmd->cmd == NULL)
				printf("%s: %s: command not found\n", ft_progname(), cmd->args[0]),
				discard_cmd(cmd),
				minishell_cleanup(shell),
				exit(127);
			execve(cmd->cmd, cmd->args, cmd->envp);
			discard_cmd(cmd);
			minishell_cleanup(shell);
			perror("execve");
			exit(126);
		}
		else
		{
			waitpid(pid, NULL, 0);
			cmd->ret = WEXITSTATUS(pid);
		}
		shell->exit = cmd->ret;
		discard_cmd(cmd);
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	return (0);
}
