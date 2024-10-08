/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/18 10:18:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>

int	minishell_prompt(t_minishell_control *shell)
{
	int			tty;

	if (!shell)
		return (EXIT_FAILURE);
	if (!isatty(STDIN_FILENO))
		shell->input = readline("");
	else
		shell->input = readline("nrobinso - bgoulard $ ");
	if (shell->input == NULL)
	{
		tty = isatty(STDIN_FILENO);
		shell->shoulcontinue = false;
		if (tty)
			printf("exit\n");
	}
	return (EXIT_SUCCESS);
}
