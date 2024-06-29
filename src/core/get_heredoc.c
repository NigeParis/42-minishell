/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:31:23 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/29 15:14:54 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_heredoc_init(t_pipex *pipex, int argc, char *argv[])
{
	pipex->fdin = -1;
	pipex->fdout = -1;
	pipex->pipe_doc[0] = -1;
	pipex->pipe_doc[1] = -1;
	pipex->doc = 0;
	pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipex->fdout == -1)
	{
		close(pipex->pipe_doc[0]);
		perror("outfile");
		exit (0);
	}
}

int	ft_heredoc(t_pipex *pipex, t_cmd_to_exec *cmd)
{
	if (cmd->ac < 1)
	{
		ft_putstr_fd("pipex: format args \
			\"here_doc LIMITER \"\n", STDERR_FILENO);
		return (1);
	}
	ft_heredoc_init(pipex, cmd->ac, cmd->argv);
	ft_here_doc(pipex, cmd);
	return (0);
}

void	ft_heredoc_cleanup(t_pipex *pipex)
{
	if (pipex->doc != 0)
	{
		if (pipex->pipe_doc[0] != -1)
			close(pipex->pipe_doc[0]);
		close(pipex->pipe_doc[1]);
	}
}

void	ft_here_doc(t_pipex *pipex, t_cmd_to_exec *cmd)
{
	char	*str;
	int		ret;		

	str = NULL;
	ret = pipe(pipex->pipe_doc);
	if (ret < 0)
		perror("heredoc");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		str = get_next_line(0);
		if ((ft_strncmp(str, cmd->argv[2], ft_strlen(cmd->argv[2])) == 0))
		{
			if ((ft_strlen(str) - 1) == ft_strlen(cmd->argv[2]))
			{
				break ;
			}
		}
		ft_putstr_fd(str, pipex->pipe_doc[1]);
		ft_free_tab(str);
	}
	ft_free_tab(str);
	close(pipex->pipe_doc[1]);
}
