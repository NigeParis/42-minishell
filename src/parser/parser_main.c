/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:56:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:42:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_types.h"
#include "parser.h"
#include <stdio.h>

int	parser(t_minishell_control *ctrl, char *str)
{
	ctrl->input = str;
	printf("ctrl %p\n", ctrl);
	init_parser_line(ctrl->prs);
	ctrl->preparsed = preparse_cmds(ctrl->input, ctrl->prs);
	return (0);
}
