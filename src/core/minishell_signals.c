/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:17:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/01 11:32:34 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n ici plouf \n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}

	if (signum == SIGQUIT)
	{
		printf("Quit (core dumped)");
		printf("\n");	
	}
	
}

void	signal_init(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
