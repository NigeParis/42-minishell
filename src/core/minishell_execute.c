/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 15:59:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include <stdio.h>
#include <sys/wait.h>


int	minishell_execute(t_minishell_control *shell)
{
	t_cmd	*cmd;
	size_t	i;

	printf("minishell_execute %p\n", shell);
	cmd = parser_get_cmd(shell->preparsed, shell); 
	printf("cmd %p\n", cmd);
	while (cmd)
	{
		printf("cmd %s\n", cmd->cmd);
		printf("cmd %d\n", cmd->argc);
		i = 0;
		while (cmd->args[i])
		{
			printf("[%zu] %s\n", i, cmd->args[i]);
			i++;
		}
		i = 0;
		while (cmd->envp[i] && i < 10)
		{
			printf("[%zu] %s\n", i, cmd->envp[i]);
			i++;
		}
		if (cmd->envp[i])
		{
			printf(" -- rest of env ommited from log...\n");
		}

		int pid = fork();
		if (pid == 0)
		{
			execve(cmd->cmd, cmd->args, cmd->envp);
			perror("execve");
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	printf("minishell_execute end\n");
	return (0);
}
