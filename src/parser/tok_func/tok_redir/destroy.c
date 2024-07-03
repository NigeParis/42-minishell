/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:09:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:02:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <stdlib.h>

void	destroy_redir(t_preparsed_node *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->value;
	if (redir->src_file)
		free(redir->src_file);
	if (redir->target_file)
		free(redir->target_file);
	free(node->value);
	free(node);
	return ;
}
