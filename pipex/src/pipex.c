/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 11:21:52 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(t_pipex *pipex, int argc, char *argv[])
{
	pipex->path = 0;
	pipex->paths = 0;
	pipex->path_cmd = 0;
	pipex->cmds = 0;
	pipex->valid_cmd = 0;
	pipex->all_cmd_valid = 0;
	pipex->nbr_cmds = (argc - 4);
	pipex->nb_argc = argc;
	pipex->parse_flag = 0;
	pipex->fdin = -1;
	pipex->fdout = -1;
	pipex->uni_path_flag = 0;
	pipex->uni_cmd = 0;
	pipex->uni_path = 0;
	pipex->cmd_not_flag = 0;
	pipex->doc = 0;
	pipex->lastcmd_flag = 1;
	ft_open_files(pipex, argc, argv);
}


int 	checkfile_read_and_exists(char *file)
{
	if (access(file, F_OK) == -1)
	{
		perror(file);
		exit (0);
	}
	else if (access(file, R_OK) == -1)
	{
		perror(file);
		exit (0);
	}
	return(1);
}





void	ft_open_files(t_pipex *pipex, int argc, char *argv[])
{
	
	if (checkfile_read_and_exists(argv[1]))
	{
		if (access(argv[1], F_OK | R_OK) == 0)
			pipex->fdin = open(argv[1], O_RDONLY, 0731);
	}
	if (pipex->lastcmd_flag == 2)
	{
		pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
		if (pipex->fdout == -1)
		{
			close_fd(pipex, 0);
			perror("outfile");
			exit (0);
		}
	}	
}



int	ft_pipex(t_pipex *pipex, int argc, char *argv[])
{
	if (argc < 3)
	{
		ft_printf_fd(2, "pipex: format args \"file1 cmd1 cmd2... file2\"\n");
		return (1);
	}
	ft_init(pipex, argc, argv);
	return (0);
}

void	cleanup_pipex_end(t_pipex *pipex)
{
	ft_heredoc_cleanup(pipex);
	ft_cleanup(pipex, 8);
	close_fd(pipex, 10);
}

int	pipex(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		i;
	char str[] = ">";

	if (ft_strcmp (argv[1], "here_doc") == 0)
	{
		i = 3;
		if (ft_heredoc(&pipex, argc, argv))
			return (1);
	}
	else
	{
		i = 2;
		if (ft_pipex(&pipex, argc, argv))
			return (1);
	}
	while (i <= argc - 2)
	{
		if (ft_strcmp(str, ">") == 0)
		{
			ft_putstr_fd("HELLO", 1);
			pipex.lastcmd_flag = 2;
			ft_open_files(&pipex, argc, argv);
		}
		ft_pipes(&pipex, argv, env, i);
		i++;
	}
	while (wait(NULL) > 0)
		;
	cleanup_pipex_end(&pipex);
	return (0);
}
