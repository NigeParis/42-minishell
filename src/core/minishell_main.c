/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:08:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"

#include <stdlib.h>
#include <unistd.h>

int	mini_main(int ac, char **av, char **envp)
{
	t_minishell_control	ctrl;
	int					tty;

	if (setup_minishell(&ctrl, ac, av, envp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	minishell_loop(&ctrl);
	return (minishell_cleanup(&ctrl));
}
