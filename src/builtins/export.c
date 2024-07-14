/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/09 13:16:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include <unistd.h>

int export_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int	i;
	char *val;

	i = 1;
	while (cmd->ac > i)
	{
		val = ft_strchr(cmd->argv[i], '=') + 1;
		if (val == (void *)1)
		{
			add_to_buff("export: no value provided\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		cmd->argv[i][val - cmd->argv[i] - 1] = '\0';
		set_env(&ctrl->env, cmd->argv[i++], val);
	}
	return (EXIT_SUCCESS);
}
