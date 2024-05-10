/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 22:30:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include <error.h>
#include <stdio.h>
#include <unistd.h>

int	cd(t_minishell_control *ctrl, t_cmd *cmd)
{
	char	*homedir;
	char	*oldpwd;
	char	*target;

	homedir = get_env(ctrl->env, "HOME");
	oldpwd = get_env(ctrl->env, "OLD_PWD");
	if (cmd->argc > 2)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO),
			EXIT_FAILURE);
	if (cmd->argc == 1)
		target = homedir;
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		target = oldpwd;
	else
		target = cmd->args[1];
	if (chdir(target) == -1)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		perror(target);
		return (EXIT_FAILURE);
	}
	set_env(&ctrl->env, "OLD_PWD", get_env(ctrl->env, "PWD"));
	set_env(&ctrl->env, "PWD", target);
	return (EXIT_SUCCESS);
}
