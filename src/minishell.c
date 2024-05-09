/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:42:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 10:17:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_addons.h"
#include "ft_string.h"
#include "ft_vector.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <errno.h>

// here we can play with the prompt to do things like:
// - display the current directory
// - display the user name
// ... and many more

int	error_singleton(int *error_set)
{
	static int	error = 0;

	if (error_set != NULL)
		error = *error_set;
	*error_set = error;
	return (error);
}

const char *prompt(t_minishell_control *control)
{
	(void)control;
	return ("minishell $> ");
}

// we check if the input is NULL to know if the user pressed Ctrl-do
int read_input(t_minishell_control *control)
{
	control->input = readline(prompt(control));
	if (control->input == NULL)
		control->exit = 1;
	return (EXIT_SUCCESS);
}

char **minishell_split(const char *input)
{
	int db_quote;
	int si_quote;
	size_t i;
	size_t j;
	size_t nb_words;
	size_t word_len;
	char **ret;

	db_quote = 0;
	si_quote = 0;
	nb_words = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '"' && !si_quote)
			db_quote = !db_quote;
		if (input[i] == '\'' && !db_quote)
			si_quote = !si_quote;
		if (input[i] == ' ' && !db_quote && !si_quote)
			nb_words++;
		i++;
	}
	if (input[i - 1] != ' ')
		nb_words++;
	ret = malloc(sizeof(char *) * (nb_words + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	si_quote = 0;
	db_quote = 0;
	word_len = 0;
	while (i < nb_words)
	{
		while (input[j] && (input[j] != ' ' || db_quote || si_quote))
		{
			if (input[j] == '"' && !si_quote)
				db_quote = !db_quote;
			if (input[j] == '\'' && !db_quote)
				si_quote = !si_quote;
			j++;
			word_len++;
		}
		ret[i] = ft_strndup(input + j++ - word_len, word_len);
		if (ret[i] == NULL)
			return (ft_free_2d((void **)ret), NULL);
		i++;
		word_len = 0;
	}
	ret[i] = NULL;
	return (ret);
}

int parse_input(t_minishell_control *control)
{
	char	**words;

	if (!control->input || ft_strlen(control->input) == 0)
		return (EXIT_SUCCESS);
	printf("input: %p (%s)\n", control->input, __func__);
	control->words = minishell_split(control->input);
	printf("words: %p (%s)\n", (void *)control->words, __func__);
	return (EXIT_SUCCESS);
	(void)control;
}

int execute(t_minishell_control *control)
{
	ft_putstr_fd("debug::", STDERR_FILENO);
	ft_putstr_fd("line: \'", STDOUT_FILENO);
	ft_putendl_fd(control->input, STDOUT_FILENO);
	ft_putstr_fd("\'\n", STDOUT_FILENO);
	printf("words %p\n", (void *)control->words);
	for (size_t i = 0; control->words && i < ft_len_2d((const void **)control->words); i++)
	{
		ft_putstr_fd("word: \'", STDOUT_FILENO);
		ft_putstr_fd(control->words[i], STDOUT_FILENO);
		ft_putstr_fd("\'\n", STDOUT_FILENO);
	}
	ft_free_2d((void **)control->words);
	free(control->input);
	return (EXIT_SUCCESS);
}

void destroy_pair_deep(void *pair)
{
	t_pair	*pair_ptr;

	pair_ptr = pair;
	free(pair_ptr->first);
	free(pair_ptr->second);
	free(pair_ptr);
}

void cleanup(t_minishell_control *control)
{
	ft_vec_apply(control->env, destroy_pair_deep);
	ft_vec_destroy(&control->env);
	free(control->input);
}

int	create_env(t_minishell_control *ctrl, const char **envp)
{
	size_t	i;
	t_pair	*pair;

	i = 0;
	ctrl->env = ft_vec_from_size(ft_len_2d((const void **)envp));
	while (envp[i])
	{
		pair = malloc(sizeof(t_pair));
		if (pair == NULL)
			return (EXIT_FAILURE);
		pair->first = ft_strdup(envp[i]);
		((char *)pair->first)[ft_strchr(envp[i], '=') - envp[i]] = '\0';
		pair->second = ft_strdup(ft_strchr(envp[i], '=') + 1);
		ft_vec_add(&ctrl->env, pair);
		i++;
	}
	return (EXIT_SUCCESS);
}

int setup(t_minishell_control *control, int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	ft_bzero(control, sizeof(t_minishell_control));
	if (create_env(control, (const char **)envp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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

int minishell_print_error(void)
{
	ft_putendl_fd("minishell: error", STDERR_FILENO);
	return (EXIT_FAILURE);
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

	if (setup(&control, ac, av, envp))
		return (minishell_print_error());
	read_input(&control);
	while (should_exit(&control) == 0)
	{
		if (parse_input(&control) || execute(&control) || \
		read_input(&control))
			return (minishell_print_error());
	}
	ret = control.ret;
	cleanup(&control);
	return (ret);
}
