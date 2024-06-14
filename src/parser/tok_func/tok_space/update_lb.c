/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 13:00:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "parser_types.h"

bool prepn_space_update_line_buffer(t_preparsed_node *node, const char *line, size_t *offset)
{
	if (ft_isspace(line[*offset]))
	{
		while (ft_isspace(line[*offset]))
			(*offset)++;
		return (true);
	}
	return (false);
}
