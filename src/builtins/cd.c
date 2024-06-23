/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 13:14:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>
#include <sys/param.h>

int	cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	char	*pwd;
	char	*homedir;
	char	*oldpwd;
	char	*target;
	char	*buff;

	homedir = get_env(ctrl->env, "HOME");
	oldpwd = get_env(ctrl->env, "OLDPWD");
	pwd = get_env(ctrl->env, "PWD");
	if (cmd->ac > 2)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO),
			EXIT_FAILURE);
	if (cmd->ac == 1)
		target = homedir;
	else if (ft_strcmp(cmd->argv[1], "-") == 0)
		target = oldpwd;
	else
		target = cmd->argv[1];
	if (chdir(target) == -1)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		perror(target);
		return (EXIT_FAILURE);
	}
	buff = malloc(PATH_MAX);
	if (!buff)
		return (EXIT_FAILURE);
	set_env(&ctrl->env, "OLDPWD", pwd);
	set_env(&ctrl->env, "PWD", getcwd(buff, PATH_MAX));
	free(buff);
	return (EXIT_SUCCESS);
}
