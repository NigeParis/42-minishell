/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/28 13:25:15 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include <stdio.h>

int export_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int	i;

	i = 1;
	while (cmd->ac > i)
	{
		if (ft_strchr(cmd->argv[i], '='))
		{
			set_env(&ctrl->env, cmd->argv[i++], NULL);
			continue;
		}
		printf("export: not a valid identifier\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
