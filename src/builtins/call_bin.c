/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:20:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/24 09:16:01 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell_types.h"
#include "parser_types.h"

#include <stdio.h>

void	call_bin(t_minishell_control *shell, t_cmd_to_exec *cmd)
{
	int	(*builtin)(t_minishell_control *, t_cmd_to_exec *);

	builtin = get_builtin(cmd->argv[0]);
	builtin(shell, cmd);
	shell->exit = cmd->status;
}
