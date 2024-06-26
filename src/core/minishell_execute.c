/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/26 14:50:56 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "pipex.h"


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

int (*get_builtin(const char *cmd))(t_minishell_control *, t_cmd_to_exec *)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (&cd_main);
	if (ft_strcmp(cmd, "env") == 0)
		return (&env_main);
	if (ft_strcmp(cmd, "exit") == 0)
		return (&exit_main);
	if (ft_strcmp(cmd, "export") == 0)
		return (&export_main);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (&pwd_main);
	if (ft_strcmp(cmd, "unset") == 0)
		return (&unset_main);
	return (NULL);
}


t_minishell_control *testminictrl(void)   // ADDED because dont know how to plug in the real one
{
    t_minishell_control *minictrl;

    minictrl = malloc(sizeof(t_minishell_control));
    
	minictrl->input = NULL;
	minictrl->env = NULL;
	minictrl->exit = 0;
	minictrl->preparsed = NULL;
	minictrl->prs = NULL;

    return (minictrl);
}



void	ft_init(t_pipex *pipex)
{

	pipex->fdout = -1;
	pipex->fdin = -1;
	pipex->child_pid = -1;
    

}

int	minishell_execute(t_minishell_control *shell)
{
	int				(*builtin)(t_minishell_control *, t_cmd_to_exec *);
	t_cmd_to_exec	*cmd;
	t_pipex pipex;
	t_redir *redir = NULL;


	size_t	i;
    ft_init(&pipex);

	shell->exit = 0;
	cmd = parser_get_cmd(shell->preparsed, shell);
	while (cmd && shell->exit == 0)
	{
		
		//redir = (t_redir*)cmd->redir_to_do->data;
		redir = test_redir_ls();	  // crash here argv->redir-to->data absent ?





		make_pipe(&pipex, cmd);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);





















	
		
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	return (0);
}
