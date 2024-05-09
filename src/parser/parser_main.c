/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:56:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 17:44:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell_types.h"

// replace this - temporary
char	**parse_words(const char *str)
{
	return (ft_split(str, ' '));
}

int	parser(t_minishell_control *ctrl, char *str)
{
	ctrl->input = str;
	ctrl->words = parse_words(ctrl->input);
	return (0);
}
