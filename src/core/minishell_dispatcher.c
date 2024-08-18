/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_dispatcher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:22:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/18 10:22:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_addons.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"

int	dispatcher(int pid, t_minishell_control *sh, t_cmd_to_exec *cmd,
		int *p_infos)
{
	int	p_fd[2];
	int	pp_fd[2];

	set_pipe(p_fd, p_infos[0], p_infos[1]);
	set_pipe(pp_fd, p_infos[2], p_infos[3]);
	if (pid == -1)
		return (ft_perror("fork"), exec_cl(sh), EXIT_FAILURE);
	if (pid == 0)
		child_exec(sh, cmd, p_fd, (int *)pp_fd);
	else
		parent_exec(sh, cmd, pid, pp_fd);
	return (EXIT_SUCCESS);
}
