/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 15:28:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	mini_main(int ac, char **av, char **envp)
{
	t_minishell_control	ctrl;
	int					tty;

	if (setup_minishell(&ctrl, ac, av, envp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	minishell_loop(&ctrl);
	tty = isatty(STDIN_FILENO);
	if (tty)
		printf("exit\n");
	return (minishell_cleanup(&ctrl));
}
