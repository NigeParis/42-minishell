/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 12:53:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_char.h"
#include "ft_vector.h"
#include "ft_string.h"

#include "builtins.h"
#include "minishell.h"
#include "minishell_types.h"

#include <unistd.h>

static int	print_export_env(t_vector *ev)
{
	t_pair	*pair;
	size_t	i;

	i = 0;
	while (i < ev->count)
	{
		pair = ft_vec_at(ev, i);
		add_to_buff("export ", STDOUT_FILENO);
		add_to_buff(pair->first, STDOUT_FILENO);
		add_to_buff("=\"", STDOUT_FILENO);
		add_to_buff(pair->second, STDOUT_FILENO);
		add_to_buff("\"\n", STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}

static bool	bad_key(const char *str)
{
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (true);
	while (*str && *str != '=')
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (true);
		str++;
	}
	return (false);
}

static void	perr_exp(const char *str)
{
	add_to_buff(ft_progname(), STDERR_FILENO);
	add_to_buff(": ", STDERR_FILENO);
	add_to_buff("export: `", STDERR_FILENO);
	add_to_buff(str, STDERR_FILENO);
	add_to_buff("': not a valid identifier\n", STDERR_FILENO);
}

int	export_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int		i;
	char	*val;
	char	*key;

	if (cmd->ac == 1)
		return (print_export_env(ctrl->env), cmd->status = EXIT_SUCCESS,
			EXIT_SUCCESS);
	i = 1;
	while (cmd->ac > i)
	{
		key = cmd->argv[i];
		if (bad_key(key))
			return (perr_exp(key), cmd->status = 1, EXIT_FAILURE);
		val = ft_strchr(cmd->argv[i], '=') + 1;
		if (val == (void *)1)
		{
			i++;
			continue ;
		}
		cmd->argv[i][val - cmd->argv[i] - 1] = '\0';
		set_env(&ctrl->env, cmd->argv[i++], val);
	}
	return (EXIT_SUCCESS);
}
