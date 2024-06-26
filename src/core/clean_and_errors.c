/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/26 16:57:28 by nrobinso         ###   ########.fr       */
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

void	close_fdout(t_pipex *pipex)
{
	
	if (pipex->fdout != -1)
		close (pipex->fdout);
	
}

void	close_fdin(t_pipex *pipex)
{
	
	if (pipex->fdin != -1)
		close (pipex->fdin);
	
}


void    close_fd(int *fd)
{
    if (*fd != -1)
    {
        close(*fd);
        *fd = -1;
    }    
}
