/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:16:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
