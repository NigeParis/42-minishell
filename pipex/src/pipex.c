/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/04 17:04:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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





void	ft_open_files(t_pipex *pipex, char *infile, char *outfile)
{
	
	if (checkfile_read_and_exists(infile))
	{
		if (access(infile, F_OK | R_OK) == 0)
			pipex->fdin = open(infile, O_RDONLY, 0731);
	}
	
	pipex->fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (pipex->fdout == -1)
	{
		close_fd(pipex, 0);
		perror("outfile");
		exit (0);
	}

}



int	ft_pipex(t_pipex *pipex, char *infile, char *outfile)
{
	ft_init(pipex, infile, outfile);
	return (0);
}


int	execute(t_cmd_to_exec *args,  t_pipex *pipex)
{
	int		i;
	char str[] = "x";

	
	i = 2;
	if (ft_pipex(pipex, "infile", "outfile"))
		return (1);
	
	while (i <= args->ac)
	{
		if (ft_strcmp(str, ">") == 0)
		{
			ft_putstr_fd("HELLO", 1);
			//ft_open_files(pipex, args->ac, args->argv);
		}
		ft_pipes(pipex, args, i);
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
