/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/25 15:19:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_args.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	print_redirs(t_list *redirs)
{
	t_list	*node;
	t_redir	*redir;

	node = redirs;
	printf("redirs:\n");
	while (node)
	{
		redir = node->data;
		printf("\t\t");
		if (redir->flag == RDIR_STD)
			printf("%d", redir->src_std);
		else
			printf("%s", redir->src_file);
		if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT
		&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			printf(" << ");
		else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
			printf(" < ");
		else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT
		&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			printf(" >> ");
		else
			printf(" | ");
		if (redir->target_file)
			printf("%s", redir->target_file);
		else
			printf("%d", redir->target_std);
		printf("\n");
		node = node->next;
	}
	printf("\n\n");
}

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
	print_redirs(cmd->redir_to_do);
}

void discard_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;
	char	*nd;

	if (cmd == NULL)
		return 
		(void) printf("error on error::cmd is NULL\n");
	if (cmd->argv)
		ft_free_2d((void **)cmd->argv), cmd->argv = NULL;
	if (cmd->env)
		ft_free_2d((void **)cmd->env), cmd->env = NULL;
	if (cmd->redir_to_do)
		ft_ll_clear(&cmd->redir_to_do, free);
	if (cmd->construction_vector)
	{
		ft_vec_apply(cmd->construction_vector, free);
		ft_vec_destroy(&cmd->construction_vector);
	}
	cmd->redir_to_do = NULL;
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
void	signal_init_child(void);

int	minishell_execute(t_minishell_control *shell)
{
	int				(*builtin)(t_minishell_control *, t_cmd_to_exec *);
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
		if (cmd && !cmd->cmd_path && cmd->ac >= 1 && get_builtin(cmd->argv[0]))
		{
			printf("builtin: %s detected\n", cmd->argv[0]);
			// run builtin here
			builtin = get_builtin(cmd->argv[0]);
			builtin(shell, cmd);
			discard_cmd(cmd);
			cmd = parser_get_cmd(shell->preparsed, shell);
			continue ;
		}
		int pid = fork();
		if (pid == 0)
		{
			signal_init_child();
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
			waitpid(pid, &cmd->status, 0);
			if (WIFSIGNALED(cmd->status))
			{
				printf("child process killed by signal %d\n", WTERMSIG(cmd->status));
				shell->exit = 128 + WTERMSIG(cmd->status);
				printf("%s : %d %s %s\n", ft_progname(), pid,
				strsignal(WTERMSIG(cmd->status)), cmd->argv[0]);
			}
			else
				shell->exit = WEXITSTATUS(cmd->status);
			if (DEBUG_LVL >= 1)
				printf("cmd status: %d\n", cmd->status);
			if (DEBUG_LVL >= 2)
				print_cmd(cmd);
			discard_cmd(cmd);
		}
		cmd = parser_get_cmd(shell->preparsed, shell); 
	}
	if (shell->preparsed)
	{
		t_preparsed_node *node;
		size_t i = 0;

		while (i < shell->preparsed->count)
		{
			node = ft_vec_at(shell->preparsed, i);
			if (node && node->destroy)
				node->destroy(node);
			i++;
		}
		ft_vec_destroy(&shell->preparsed);
		shell->preparsed = NULL;
	}
	return (0);
}
