/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:20:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 14:21:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell_types.h"
#include "parser_types.h"

void	call_bin(t_minishell_control *shell, t_cmd_to_exec *cmd)
{
	int	(*builtin)(t_minishell_control *, t_cmd_to_exec *);

	builtin = get_builtin(cmd->argv[0]);
	builtin(shell, cmd);
	shell->exit = cmd->status;
}
