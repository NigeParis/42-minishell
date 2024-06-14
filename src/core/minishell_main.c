/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/04 10:44:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"
#include <stdlib.h>

int	mini_main(int ac, char **av, char **envp)
{
	t_minishell_control	ctrl;

	if (setup_minishell(&ctrl, ac, av, envp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	minishell_loop(&ctrl);
	return (minishell_cleanup(&ctrl));
}
