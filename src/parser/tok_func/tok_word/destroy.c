/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:40:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 15:43:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"
#include <stdlib.h>

void	destroy_word(t_preparsed_node *node)
{
	t_string	*word;

	if (node->value)
	{
		word = (t_string *)node->value;
		ft_string_destroy(&word);
	}
	free(node);
	return ;
}
