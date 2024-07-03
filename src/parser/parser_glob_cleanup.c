/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_glob_cleanup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:05:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser.h"
#include "parser_types.h"
#include <stdlib.h>

int	parser_glob_cleanup(t_parser *prs)
{
	parser_line_cleanup(prs);
	if (prs->tokens)
	{
		ft_vec_destroy(&prs->tokens);
		prs->tokens = NULL;
	}
	return (EXIT_SUCCESS);
}
