/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:43:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 09:38:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"

bool	isok_redir(const char *line, t_preparser_context *ctx)
{
	const char	*valid_rdirs[] = {">", ">>", "<", "<<", NULL};
	size_t		cr_offset;
	size_t		i;

	cr_offset = 0;
	if (line[cr_offset] == '\0' || ctx->quote_ctx != QUOTE_NONE)
		return (false);
	i = 0;
	while (valid_rdirs[i] != NULL)
	{
		if (ft_strncmp(line + cr_offset, valid_rdirs[i],
				ft_strlen(valid_rdirs[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}
