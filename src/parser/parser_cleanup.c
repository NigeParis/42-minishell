/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:42:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser.h"

void	parser_cleanup(t_parser *prs)
{
	if (prs->words)
		ft_free((void **)&prs->words);
}
