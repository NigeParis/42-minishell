/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interupt_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:16 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/20 16:05:25 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_char.h"
#include <signal.h>

void backslash_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (core dumped)", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);	
}

void Ctrl_C_handler(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDOUT_FILENO);	
	ft_putstr_fd("minishell $> ", STDOUT_FILENO);
}

void Ctrl_C_child_handler(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDOUT_FILENO);	
}