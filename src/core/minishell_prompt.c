/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/04 10:46:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>

// TODO:
// move printf("exit\n") to shell cleanup function or somewhere else cleaner
int	minishell_prompt(t_minishell_control *shell)
{
	int tty;

	shell->input = readline("minishell $> ");
	if (shell->input == NULL)
	{
		tty = isatty(STDIN_FILENO);
		if (tty)
			printf("exit\n");
		shell->exit = 0;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
