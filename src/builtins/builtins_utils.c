/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:19:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 14:14:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "ft_string_types.h"

#include <stdbool.h>
#include <unistd.h>

int	(*get_builtin(const char *cmd))(t_minishell_control *a, t_cmd_to_exec *b)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (&cd_main);
	if (ft_strcmp(cmd, "env") == 0)
		return (&env_main);
	if (ft_strcmp(cmd, "exit") == 0)
		return (&exit_main);
	if (ft_strcmp(cmd, "echo") == 0)
		return (&echo_main);
	if (ft_strcmp(cmd, "export") == 0)
		return (&export_main);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (&pwd_main);
	if (ft_strcmp(cmd, "unset") == 0)
		return (&unset_main);
	return (NULL);
}

t_string	*buff_func(t_string *set_v, bool set_f, int fd_dst)
{
	static t_string	*data[3] = {NULL};

	if (fd_dst > 3 || fd_dst < 0)
		return (NULL);
	if (set_f == true)
		data[fd_dst] = set_v;
	return (data[fd_dst]);
}

bool	add_to_buff(const char *str_to_add, int fd_dest)
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
	return ;
}
