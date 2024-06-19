/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex_wd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/19 12:03:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>

void	resolve_word(t_string *word, t_minishell_control *sh) // resolve nested '$' here
{
	if (DEBUG_LVL)
		printf("resolve_word: %s\n", word->str);
	(void)word;
	(void)sh;
}

bool	nd2ex_word(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	char *str[2];

	if (!nd->value)
		return (false);
	resolve_word(nd->value, sh);
	if (cmd->construction_vector == NULL)
		cmd->construction_vector = ft_vec_new();
	if (cmd->construction_vector->count < cmd->construction_index)
		ft_vec_add(&cmd->construction_vector, ft_strdup(""));
	str[0] = cmd->construction_vector->datas[cmd->construction_index];
	str[1] = str[0];
	if (!str[0])
		str[0] = ft_string_to_str(nd->value);
	else
		str[0] = ft_strjoin(str[1], ft_string_to_str(nd->value));
	if (str[1])
		free(str[1]);
	return (ft_string_destroy((t_string**)&nd->value), \
	ft_vec_add(&cmd->construction_vector, str[0]), free(nd), true);
}
