/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:56:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:04:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"

int	mini_main(int ac, char **av, char **envp)
{
	t_minishell_control	ctrl;

	setup_minishell(&ctrl, ac, av, envp);
	minishell_loop(&ctrl);
	return (minishell_cleanup(&ctrl));
}
