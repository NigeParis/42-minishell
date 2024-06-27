/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/27 12:26:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int	minishell_prompt(t_minishell_control *shell)
{
	int	tty;

	shell->input = readline("minishell $> ");
	if (shell->input == NULL)
	{
		
		tty = isatty(STDIN_FILENO);
		if (tty)
			printf("exit\n");	
		shell->shoulcontinue = false;
	}	
	return (EXIT_SUCCESS);
}
