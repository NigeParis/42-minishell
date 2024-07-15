/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_discard_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:23:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 12:56:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"
#include <stddef.h>
#include <stdio.h>

void	free_rdr_node(void *abst_node)
{
	t_redir	*redir;

	redir = abst_node;
	if (redir->target_file)
		free(redir->target_file);
	if (redir->src_file)
		free(redir->src_file);
	free(redir);
}

void	discard_cmd(t_cmd_to_exec *cmd)
{
	size_t	i;
	char	*nd;

	if (cmd == NULL)
		return ((void) dprintf(2, "error on error::cmd is NULL\n"));
	if (cmd->argv)
		(ft_free_2d((void **)cmd->argv), cmd->argv = NULL);
	if (cmd->env)
		(ft_free_2d((void **)cmd->env), cmd->env = NULL);
	if (cmd->redir_to_do)
		(ft_ll_clear(&cmd->redir_to_do, free_rdr_node), \
		cmd->redir_to_do = NULL);
	if (cmd->construction_vector)
	{
		ft_vec_apply(cmd->construction_vector, free);
		ft_vec_destroy(&cmd->construction_vector);
		cmd->construction_vector = NULL;
	}
	free(cmd->cmd_path);
	free(cmd);
}
