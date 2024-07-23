/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 12:58:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"
#include "parser_types.h"

#include <stdbool.h>
#include <unistd.h>

/*
** Preparse the line and create a list of preparsed nodes (tokens), the 
** preparsed nodes are stored in the parser structure in a vector.
** Todo: updat parser_destroy to free the preparsed nodes. 
**		(check method destroy on tokens).
** Todo: modify return to return an error code when failing to allocate memory.
*/
/*
			print("Error: preparse_line: unexpected token: \'%s\'\n", \
			var_ctx.unexpected); // todo add cleanup and ret err code
			print("Error: preparse_line: update_preparsed or "\
			"update_context failed\n"); // todo add cleanup and ret err code
*/

static void	print_unexpected(t_preparser_context *ctx)
{
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putstr_fd(ctx->unexpected, STDERR_FILENO);
}

int	preparse_line(t_parser *restrict p)
{
	t_preparser_context	var_ctx;
	const size_t		len = ft_strlen(p->line);

	ft_bzero(&var_ctx, sizeof(t_preparser_context));
	var_ctx.line = p->line;
	while (var_ctx.line_offset <= len)
	{
		get_next_token(p, &var_ctx);
		if (var_ctx.n_tok->type == TOK_UNKNOWN)
			var_ctx.unexpected = "Error: Unknown token";
		if (var_ctx.unexpected)
			return (print_unexpected(&var_ctx), preparser_destroy(&var_ctx, p),
				EXIT_FAILURE);
		else if (update_preparsed(p, &var_ctx) == false || update_context(p,
				&var_ctx) == false)
		{
			if (var_ctx.unexpected)
				print_unexpected(&var_ctx);
			return (preparser_destroy(&var_ctx, p), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	parser_line_init(t_parser *restrict prs)
{
	if (!prs)
		return (ft_putendl_fd("Critical error: no parser", STDERR_FILENO), \
		EXIT_FAILURE);
	if (!prs->line)
		return (ft_putendl_fd("Critical Error: parser_line_init: prs->line " \
		"is NULL", STDERR_FILENO), EXIT_FAILURE);
	prs->preparsed = ft_vec_new();
	if (!prs->preparsed)
		return (ft_putendl_fd("Error: parser_line_init: ft_vec_new failed", \
		STDERR_FILENO), EXIT_FAILURE);
	if (preparse_line(prs))
		return (EXIT_FAILURE);
	if (!prs->preparsed)
		return (ft_putendl_fd("Error: parser_line_init: prs->preparsed is " \
		"NULL", STDERR_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
