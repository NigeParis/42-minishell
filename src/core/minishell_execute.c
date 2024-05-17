/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:21:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell_types.h"
#include <stdio.h>
#include <stdlib.h>

int	minishell_execute(t_minishell_control *shell)
{
	printf("debug:\n");
	printf("Executing: %s\n", shell->input);
	printf("Words: %p\n", (void *)shell->words);
	for (size_t i = 0; shell->words && shell->words[i]; i++)
	{
		printf("word[%zu]: %s\n", i, shell->words[i]);
		free(shell->words[i]);
	}
	if (shell->words)
		ft_free((void **)&shell->words);
	if (shell->input)
		ft_free((void **)&shell->input);
	(void)shell;
	return (0);
}
