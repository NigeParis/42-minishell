/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 12:12:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	clean_cmd_path(t_pipex	*pipex)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	j = 0;
	while (pipex->cmds[0] && pipex->cmds[0][i])
	{
		if (pipex->cmds[0][i] == '/')
			flag++;
		i++;
	}
	if (!flag)
		return (-1);
	while (pipex->cmds[0][i] != '/')
		i--;
	i++;
	while (pipex->cmds[0][i])
	{
		pipex->cmds[0][j++] = pipex->cmds[0][i++];
	}
	pipex->cmds[0][j] = '\0';
	return (0);
}

int	get_cmd(t_pipex *pipex, char *argv)
{
	char *str;
	
	str = ft_strdup(argv);
	ft_toggle_char(&str, ' ', 0);
	pipex->cmds = ft_split(str, ' ');
	if (!pipex->cmds[0])
		return (-1);
	ft_make_toogle_cmd_arg(pipex);
	if ((access(pipex->cmds[0], F_OK | R_OK)) == 0)
		clean_cmd_path(pipex);
	ft_free_tab(str);
	return (0);
}


void	parse_cmd(t_pipex *pipex, int i, char *argv[], char *env[])
{
	if (pipex->uni_path_flag == 0)
	{
		if ((get_cmd(pipex, argv[i])) == -1)
		{
			ft_path(pipex, "null", env);
			ft_exec_cmd_error(pipex, "pipex: permission denied: ");
			exit(127);
		}
		else
			ft_path(pipex, pipex->cmds[0], env);
	}

	
}





void	exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[])
{
	int	ret;

	ret = -1;
	
	parse_cmd(pipex, i, argv, env);



	if (pipex->valid_cmd == 0)
	{
		pipex->valid_cmd = 1;
		ret = execve(pipex->path, pipex->cmds, env);
	}
	if (ret == -1)
	{
		ft_exec_cmd_error(pipex, "pipex: command not found: ");
		exit(127);
	}
}

