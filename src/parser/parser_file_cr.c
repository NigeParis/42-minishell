/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_cr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:27:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/16 09:46:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "ft_args.h"
#include "ft_addons.h"
#include "parser_types.h"

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void	close_trailing_fd(int fd)
{
	if (fd >= 0 && fd <= 2)
		return ;
	if (fd > 2)
		return (close(fd), (void) 0);
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(": open :", STDERR_FILENO);
	ft_putstr_fd(ft_strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	correct_open(char *fname, t_redir *redir)
{
	if (redir && ((redir->redir_type & RDIR_MSK_MODE) == RDIR_TRUNC))
		return (open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644));
	else if (redir && ((redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND))
		return (open(fname, O_WRONLY | O_APPEND | O_CREAT, 0644));
	return (-1);
}

void	cr_file(int i, t_vector *prep)
{
	t_preparsed_node	*nd;
	t_redir				*redir;
	char				*fname;
	int					fd;

	fd = 0;
	fname = NULL;
	nd = ft_vec_at(prep, i);
	redir = nd->value;
	if ((redir && (redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT))
		return ;
	if ((redir && (redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT))
	{
		while (nd && (nd->type != TOK_WORD && nd->type != TOK_QUOTE))
			nd = ft_vec_at(prep, i++);
		if (nd && nd->type == TOK_WORD)
			fname = ((t_string *)nd->value)->str;
		else if (nd && nd->type == TOK_QUOTE)
			fname = ((t_quote_node *)nd->value)->value->str;
		if (!fname)
			return ;
		fd = correct_open(fname, redir);
	}
	return (close_trailing_fd(fd));
}

void	file_creation(t_vector *prep)
{
	t_preparsed_node	*token;
	int					i;

	i = 0;
	while (prep && (size_t)i < prep->count)
	{
		token = ft_vec_at(prep, i);
		if (token && token->type == TOK_REDIR)
			cr_file(i, prep);
		i++;
	}
}
