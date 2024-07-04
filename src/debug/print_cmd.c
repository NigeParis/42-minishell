/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:19:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:29:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "parser_types.h"
#include <stddef.h>
#include <stdio.h>

void	print_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;

	if (cmd == NULL)
	{
		dprintf(2, "cmd is NULL\n");
		return ;
	}
	dprintf(2, "cmd %s\t", cmd->cmd_path);
	dprintf(2, "\tac: %d\n", cmd->ac);
	i = 0;
	while (cmd->argv[i])
		dprintf(2, "[%zu] %s\n", i, cmd->argv[i]), i++;
	dprintf(2, "\t--\tend of args\n");
	i = 0;
	while (cmd->env[i] && i < 5)
		dprintf(2, "[%zu] %s\n", i, cmd->env[i]), i++;
	if (cmd->env[i])
		dprintf(2, "\t--\trest of env ommited from log...\n");
	print_redirs(cmd->redir_to_do);
}
