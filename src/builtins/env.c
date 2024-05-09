/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:04:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "minishell_types.h"
#include "ft_vector.h"

static void	disp_env_val(void *v_pair)
{
	const t_pair	*pair = v_pair;

	ft_putstr_fd(pair->first, 1);
	ft_putstr_fd("=", 1);
	ft_putstr_fd(pair->second, 1);
	ft_putstr_fd("\n", 1);
}

int	ft_env(t_minishell_control *ctrl, t_cmd *cmd)
{
	(void)cmd;
	ft_vec_apply(ctrl->env, disp_env_val);
	return (EXIT_SUCCESS);
}
