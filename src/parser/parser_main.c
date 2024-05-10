/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:56:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:29:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_types.h"
#include "parser.h"

int	parser(t_minishell_control *ctrl, char *str)
{
	ctrl->input = str;
	ctrl->words = parse_words(ctrl->input);
	return (0);
}
