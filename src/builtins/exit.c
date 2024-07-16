/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 17:43:14 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_args.h"
#include "ft_addons.h"
#include "ft_string.h"
#include "minishell_types.h"
#include "parser_types.h"

static void	print_err(t_cmd_to_exec *cmd, char *msg)
{
	add_to_buff(ft_progname(), STDERR_FILENO);
	add_to_buff(": exit :", STDERR_FILENO);
	add_to_buff(cmd->argv[1], STDERR_FILENO);
	add_to_buff(msg, STDERR_FILENO);
	add_to_buff("\n", STDERR_FILENO);
}

static int	flag_arg_num_error(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	if (cmd->nbr_cmds == 1)
		ctrl->shoulcontinue = false;
	return (print_err(cmd, ": numeric argument required"), cmd->status = 2, 2);
}

static void	flag_invalid_exit(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	if ((cmd->redir_to_do != NULL) || (cmd->nbr_cmds < 1))
	{
		cmd->nbr_cmds = 1;
		ctrl->shoulcontinue = true;
	}
}

int	exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	long	user_input;

	ctrl->exit = 0;
	if (cmd->ac > 2)
	{
		if (ft_str_islong(cmd->argv[1]) == false)
			return (flag_arg_num_error(ctrl, cmd));
		return (print_err(cmd, ": too many arguments"), cmd->status = 1, 1);
	}
	ctrl->shoulcontinue = false;
	user_input = ctrl->exit;
	if ((cmd->ac == 2) && (cmd->redir_to_do == NULL))
	{
		if (ft_str_islong(cmd->argv[1]) == false)
			return (print_err(cmd, ": numeric argument required"), \
			cmd->status = 2, 2);
		user_input = ft_atol(cmd->argv[1]);
	}
	while (user_input < 0)
		user_input += 256;
	user_input %= 256;
	flag_invalid_exit(ctrl, cmd);
	return (cmd->status = user_input, user_input);
}
