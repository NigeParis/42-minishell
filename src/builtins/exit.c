/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:02:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"

int	exit_main(t_minishell_control *ctrl, t_cmd *cmd)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->argc > 2)
	{
		ctrl->exit = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	cmd->ret = 0;
	if (cmd->argc == 2)
	{
		if (ft_str_isdigit(cmd->args[1]) == false)
		{
			ctrl->ret = 1;
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(cmd->args[1], STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			return (1);
		}
		cmd->ret = ft_atoi(cmd->args[1]);
	}
	ctrl->exit = cmd->ret;
	return (ctrl->exit);
}
