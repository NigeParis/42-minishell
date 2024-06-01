/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:49:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell_types.h"
#include <stdio.h>
#include <stdlib.h>

int	minishell_execute(t_minishell_control *shell)
{
	t_cmd	*cmd;
	size_t	i;

	cmd = parser_get_cmd(shell->preparsed);
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
		while (cmd->envp[i])
		{
			printf("[%zu] %s\n", i, cmd->envp[i]);
			i++;
		}
		cmd = parser_get_cmd(shell->preparsed);
	}
	return (0);
}
