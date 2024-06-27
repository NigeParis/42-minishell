/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/27 17:04:46 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "parser_types.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/types.h>


int	minishell_should_exit(t_minishell_control *shell)
{
	if (shell->shoulcontinue != true)
		return (1);
	return (0);
}

int	minishell_parse(t_minishell_control *shell)
{
	if (!shell->input)
		return (EXIT_SUCCESS);
	((t_parser *)shell->prs)->line = shell->input;
	parser_line_init(shell->prs);
	shell->preparsed = ((t_parser*)shell->prs)->preparsed;
	if (shell->preparsed == NULL || shell->preparsed->count == 0)
		return (
		printf("%s: preparsed null or no elements\n", __func__),
		EXIT_SUCCESS);
	if (minishell_execute(shell))
		return (parser_line_cleanup(shell->prs), EXIT_FAILURE);
	add_history(shell->input);
	return (parser_line_cleanup(shell->prs), EXIT_SUCCESS);
}


void	minishell_loop(t_minishell_control *shell)
{
	printf("minishell_loop %p\n", shell);
	while (1)
	{
		signal(SIGINT, Ctrl_C_handler);   /* Ctrl-c handler*/
        signal(SIGQUIT, SIG_IGN);          /* desactivates Ctrl-\ */
		
		
		if (minishell_prompt(shell))
		{
				break ;
		}
		if (minishell_parse(shell))
		{
				break ;
		}
		if (minishell_should_exit(shell))
		{
				break ;
		}

	
	}
	printf("minishell_loop end\n");
}
