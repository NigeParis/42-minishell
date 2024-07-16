/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/08 20:55:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_vector.h"
#include "minishell_types.h"
#include "ft_vector.h"
#include "parser_types.h"

#include <unistd.h>
#include <stdlib.h>

static void	disp_env_val(void *v_pair)
{
	const t_pair	*pair = v_pair;

	add_to_buff(pair->first, STDOUT_FILENO);
	add_to_buff("=", STDOUT_FILENO);
	add_to_buff(pair->second, STDOUT_FILENO);
	add_to_buff("\n", STDOUT_FILENO);
}

int	env_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	(void)cmd;
	ft_vec_apply(ctrl->env, disp_env_val);
	return (EXIT_SUCCESS);
}
