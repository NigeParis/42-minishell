/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex_wd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 16:43:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdlib.h>

void	resolve_word(t_string *word, t_minishell_control *sh) // resolve nested '$' here
{
	(void)word;
	(void)sh;
}

bool	nd2ex_word(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	char *str[2];

	if (!nd->value)
		return (false);
	resolve_word(nd->value, sh);
	if (cmd->construction_vector->count < cmd->construction_index)
		ft_vec_add(&cmd->construction_vector, ft_strdup(""));
	str[0] = cmd->construction_vector->datas[cmd->construction_index];
	str[1] = str[0];
	if (!str[0])
		str[0] = ft_string_to_str(nd->value);
	else
		str[0] = ft_strjoin(str[1], ft_string_to_str(nd->value));
	ft_string_destroy((t_string**)&nd->value);
	ft_vec_add(&cmd->construction_vector, str[0]);
	if (str[1])
		free(str[1]);
	free(nd);
	return (true);
}
