/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:42:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 14:13:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include "ft_vector.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

// here we can play with the prompt to do things like:
// - display the current directory
// - display the user name
// ... and many more

const char *prompt(t_minishell_control *control)
{
	(void)control;
	return ("minishell $> ");
}

// we check if the input is NULL to know if the user pressed Ctrl-do

void read_input(t_minishell_control *control)
{
	control->input = readline(prompt(control));
	if (control->input == NULL)
		control->exit = 1;
}

void parse_input(t_minishell_control *control)
{
	(void)control;
}

void execute(t_minishell_control *control)
{
	ft_putstr_fd("debug::", STDERR_FILENO);
	ft_putstr_fd("line: \'", STDOUT_FILENO);
	ft_putendl_fd(control->input, STDOUT_FILENO);
	ft_putstr_fd("\'\n", STDOUT_FILENO);
	free(control->input);
}

void cleanup(t_minishell_control *control)
{
	ft_vec_destroy(&control->env);
	free(control->input);
}

size_t	ft_strlen_array(char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

void setup(t_minishell_control *control, int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	ft_bzero(control, sizeof(t_minishell_control));
	control->env = ft_vec_from_array((void **)envp, ft_strlen_array(envp));
}

// should_exit check for null input because of init loop
// then we check if the input is "exit\n"
// ctrl+d is checked in read_input
//
// currently we have no parsing so we rawdawg the check on input for exit but 
// we will need to check if any command in the line is exit and exit the shell
// if it is.
// eg: "ls -l; exit ; ls -la" should exit the shell after ls -l and not execute
//	ls -la 
int should_exit(t_minishell_control *control)
{
	if (!control->input)
		return (control->exit);
	if (control->exit == 1 || ft_strncmp(control->input, "exit", 4) == 0)
		return (1);
	return (0);
}

// base loop of the shell
//  - setup
//  - loop until 'errors on alloc' 'exit' 'ctrl+d'
//    - get user input
//    - parse input
//    - execute
//  - setup return value
//  - cleanup
//  - return
int	minishell(int ac, char **av, char **envp)
{
	t_minishell_control	control;
	int					ret;

	setup(&control, ac, av, envp);
	read_input(&control);
	while (should_exit(&control) == 0)
	{
		parse_input(&control);
		execute(&control);
		read_input(&control);
	}
	ret = control.ret;
	cleanup(&control);
	return (ret);
}
