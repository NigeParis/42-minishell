/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:19:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/05 15:10:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"
#include "minishell.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

t_string	*buff_func(t_string *set_v, bool set_f, int fd_dst)
{
	static t_string *data[3] = {NULL};
	if (fd_dst > 3 || fd_dst < 0)
		return (NULL);
	if (set_f == true)
		data[fd_dst] = set_v;
	return (data[fd_dst]);
}

bool	add_to_buff(char *str_to_add, int fd_dest)
{
	t_string	*current_buff;

	current_buff = buff_func(NULL, false, fd_dest);
	if (current_buff == NULL)
		current_buff = ft_string_new(1);
	if (ft_string_append(current_buff, str_to_add) == -1)
		return (false);
	buff_func(current_buff, true, fd_dest);
	return (true);
}

void	destroy_buff(int fd_dest)
{
	t_string	*buff;

	buff = buff_func(NULL, false, fd_dest);
	if (buff)
		ft_string_destroy(&buff);
	buff_func(NULL, true, fd_dest);
	if (DEBUG_LVL > 30)
		dprintf(STDERR_FILENO, "<destroybuff %d>", fd_dest);
	return ;
}

void	print_buff(int fd_dest)
{
	t_string	*buff;

	buff = buff_func(NULL, false, fd_dest);
	if (!buff)
		return ;
	ft_putstr_fd(buff->str, fd_dest);
	destroy_buff(fd_dest);
	if (DEBUG_LVL > 20)
		dprintf(STDERR_FILENO, "<buff %d printed + free'd>\n", fd_dest);
	return ;
}
