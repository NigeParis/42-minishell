/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/05 15:38:47 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_free_double_tab(char *tab[])
{
	int	y;

	y = 0;
	while (tab && tab[y])
	{
		free(tab[y]);
		y++;
	}
	if (tab)
		return (free(tab));
}


void	ft_free_tab(char *tab)
{
	if (tab)
		free (tab);
}

void	close_fd(t_pipex *pipex)
{
	
	if (pipex->fdout != -1)
		close (pipex->fdout);
	
}

// void	ft_exec_cmd_error(t_pipex *pipex, char *message)
// {
// 	char	str[ERROR_MSG_SIZE];
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (message && message[i])
// 	{
// 		str[i] = message[i];
// 		i++;
// 	}
// 	while (pipex->cmds[0] && pipex->cmds[0][j])
// 	{
// 		str[i] = pipex->cmds[0][j];
// 		j++;
// 		i++;
// 	}
// 	str[i] = '\n';
// 	i++;
// 	str[i] = '\0';
// 	ft_printf_fd(2, "%F", str);
// 	close_fd(pipex, 10);
// }
