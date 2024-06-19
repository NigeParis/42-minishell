/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 13:53:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	print_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;

	if (cmd == NULL)
	{
		printf("cmd is NULL\n");
		return ;
	}
	printf("cmd %s\t", cmd->cmd_path);
	printf("\tac: %d\n", cmd->ac);
	i = 0;
	while (cmd->argv[i])
		printf("[%zu] %s\n", i, cmd->argv[i]), i++;
	printf("\t--\tend of args\n");
	i = 0;
	while (cmd->env[i] && i < 5)
		printf("[%zu] %s\n", i, cmd->env[i]), i++;
	if (cmd->env[i])
		printf("\t--\trest of env ommited from log...\n");
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
	if (cmd->redir_to_do)
		ft_ll_clear(&cmd->redir_to_do, free);
	cmd->redir_to_do = NULL;
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
	while (cmd && shell->exit == 0)
	{
		// check for builtins
		// yes branch-> 
			// execute the command as fun bellows but use t_minishell_control 
			// and other fun stuff
		int pid = fork();
		if (pid == 0)
		{
			// setup sigaction here for child process aka SIGSEGV etc...
			// setup redirections
			// execute the command :: see below
			if (cmd->cmd_path == NULL)
			{
				printf("%s: %s: command not found\n", ft_progname(), cmd->argv[0]),
				discard_cmd(cmd),
				minishell_cleanup(shell),
				exit(127);
			}
			execve(cmd->cmd_path, cmd->argv, cmd->env);
			// if execve fails
			discard_cmd(cmd);
			minishell_cleanup(shell);
			perror("execve");
			exit(126);
		}
		else // parent
		{
			waitpid(pid, NULL, 0);
			cmd->status = WEXITSTATUS(pid);
			// shell->exit = cmd->status;
			if (DEBUG_LVL >= 1)
				printf("cmd status: %d\n", cmd->status);
			if (DEBUG_LVL >= 2)
				print_cmd(cmd);
			discard_cmd(cmd);
		}
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	return (0);
}
