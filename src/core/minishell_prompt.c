/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:36:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>

int	minishell_prompt(t_minishell_control *shell)
{
	const char	*emotion[2] = {"\U0001f600", "\U0001f621"};
	char		prompt[100];
	const char	*print;
	int			tty;

	if (!shell)
		return (EXIT_FAILURE);
	tty = isatty(STDIN_FILENO);
	prompt[0] = '\0';
	ft_strlcat(prompt, emotion[shell->exit != 0], 100);
	ft_strlcat(prompt, PROMPT, 100);
	if (tty)
		print = prompt;
	else
		print = "";
	shell->input = readline(print);
	if (shell->input == NULL)
	{
		shell->shoulcontinue = false;
		if (tty)
			printf("exit\n");
	}
	return (EXIT_SUCCESS);
}
