/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 18:13:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"

bool	prepn_word_append(t_preparsed_node *node, const char *line, size_t offset)
{
	t_string	*val;

	val = node->value;
	if (ft_string_append_c(val, *(line + offset)) == false)
		return (false);
	return (true);
}
