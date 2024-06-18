/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 16:45:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdlib.h>

bool	nd2ex_space(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	free(nd);
	cmd->construction_index++;
	return (true);
}
