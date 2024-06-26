/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/25 15:31:58 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int 	checkfile_read_and_exists(char *file, int type)
{
	if (access(file, F_OK) == -1)
	{
		if (type == INFILE)
			perror(file);
		return (0);
	}
	else if ((access(file, W_OK) == -1) && type == OUTFILE)
	{
		perror(file);
		return (0);
	}
	else if ((access(file, R_OK) == -1) && type == INFILE)
	{
		perror(file);
		return (0);
	}	
	return(1);
}

void	ft_open_outfile_trunc(t_pipex *pipex, char *outfile)
{
	if (checkfile_read_and_exists(outfile, OUTFILE))
	{	
		pipex->fdout = open(outfile, O_WRONLY | O_TRUNC, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror(outfile);
			exit (0);
		}
	}
	else
	{
		pipex->fdout = open(outfile, O_WRONLY | O_CREAT, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror(outfile);
			exit (0);
		}
	}
}


void	ft_open_outfile_append(t_pipex *pipex, char *outfile)
{
	if (checkfile_read_and_exists(outfile, OUTFILE))
	{	
		pipex->fdout = open(outfile, O_WRONLY | O_APPEND, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror(outfile);
			exit (0);
		}
	}
	else
	{
		pipex->fdout = open(outfile, O_WRONLY | O_CREAT, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror(outfile);
			exit (0);
		}
	}
}











void	ft_open_infile(t_pipex *pipex, char *infile)
{
	if (checkfile_read_and_exists(infile, INFILE))
	{	
		pipex->fdin = open(infile, O_RDONLY, 0755);
		if (pipex->fdin == -1)
		{
			close_fdin(pipex);
			perror(infile);
			exit (0);
		}
	}
}


int	execute(t_cmd_to_exec *argv,  t_pipex *pipex)
{
	
	make_pipe(pipex, argv);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);

	return (0);
}




	// RDIR_PIPE = 1,		// 0 00 01
	// RDIR_INPUT = 2,		// 0 00 10
	// RDIR_OUTPUT = 3,	    // 0 00 11

	// RDIR_TRUNC = 4,		// 0 01 00
	// RDIR_APPEND = 8,	    // 0 10 00
	// RDIR_HEREDOC = 12,	// 0 11 00
	
	// RDIR_DUP = 16,		// 1 00 00 // >&