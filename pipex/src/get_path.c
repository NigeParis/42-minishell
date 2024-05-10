/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:01:13 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/24 10:08:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_path(t_pipex *pipex, char *cmd, char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(env[i] + 5, ':');
	ft_cleanup(pipex, 1);
	i = 0;
	pipex->valid_cmd = 1;
	while (pipex->paths && pipex->paths[i])
	{
		pipex->path_cmd = ft_strjoin(pipex->paths[i], "/");
		pipex->path = ft_strjoin(pipex->path_cmd, cmd);
		ft_cleanup(pipex, 3);
		if (access(pipex->path, F_OK | R_OK) == 0)
		{
			pipex->valid_cmd = 0;
			pipex->all_cmd_valid++;
			break ;
		}
		ft_cleanup(pipex, 1);
		i++;
	}
	ft_cleanup(pipex, 7);
	return (i);
}

int	path_absolu_valid(t_pipex *pipex, char *argv[], int i)
{
	if (access(pipex->uni_path[0], F_OK | R_OK) == 0)
	{
		if ((get_cmd(pipex, argv[i])) == -1)
		{
			ft_putstr_fd("pipex: permission denied:", 1);
			ft_cleanup(pipex, 5);
			close_fd(pipex, 10);
			exit(127);
		}
		pipex->valid_cmd = 0;
		pipex->all_cmd_valid++;
		ft_cleanup(pipex, 8);
		pipex->path = ft_strdup(pipex->uni_path[0]);
		pipex->cmds = pipex->uni_path;
		return (1);
	}
	return (0);
}

int	get_path_absolu(t_pipex *pipex, char *argv[], int i)
{
	int	j;

	j = 0;
	while (argv[i][j] != '\0' && argv[i][j] != ' ')
	{
		if (argv[i][j] == '/')
			pipex->uni_path_flag = 1;
		j++;
	}
	if (pipex->uni_path_flag)
	{
		if (pipex->uni_path)
			ft_free_double_tab(pipex->uni_path);
		pipex->uni_path = ft_split(argv[i], ' ');
		if (path_absolu_valid(pipex, argv, i))
			return (1);
		pipex->uni_path_flag = 0;
		pipex->valid_cmd = 1;
		ft_cleanup(pipex, 8);
		if (pipex->uni_path)
			ft_free_double_tab(pipex->uni_path);
	}
	return (0);
}
