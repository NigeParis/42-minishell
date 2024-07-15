/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:20:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 12:52:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_types.h"
#include "parser_types.h"
#include <stdio.h>

void	print_symbol(t_redir *redir)
{
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT \
	&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
		dprintf(2, " << ");
	else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		dprintf(2, " < ");
	else if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT \
	&& (redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
		dprintf(2, " >> ");
	else
		dprintf(2, " | ");
}

void	print_redirs(t_list *redirs)
{
	t_list	*node;
	t_redir	*redir;

	node = redirs;
	dprintf(2, "redirs:\n");
	while (node)
	{
		redir = node->data;
		dprintf(2, "\t\t");
		if (redir->flag == RDIR_STD)
			dprintf(2, "%d", redir->src_std);
		else
			dprintf(2, "%s", redir->src_file);
		print_symbol(redir);
		if (redir->target_file)
			dprintf(2, "%s", redir->target_file);
		else
			dprintf(2, "%d", redir->target_std);
		dprintf(2, "\n");
		node = node->next;
	}
	dprintf(2, "\n\n");
}
