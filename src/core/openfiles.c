/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:09:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/26 15:29:37 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_file(t_pipex *pipex, t_cmd_to_exec *argv)
{
	t_redir *redir;
	// redir = (t_redir*)argv->redir_to_do->data; // crashes
	redir = test_redir_ls();	  // crash here argv->redir-to->data absent ?

	if (redir->flag == RDIR_FILE && redir->redir_type == RDIR_TRUNC)
	{
		ft_open_outfile_trunc(pipex, redir->target_file);
	}

	if (redir->flag == RDIR_FILE && redir->redir_type == RDIR_APPEND)
	{
		ft_open_outfile_append(pipex, redir->target_file);
	}
	
	if (redir->flag == RDIR_FILE && redir->redir_type == 0)
	{
		ft_open_infile(pipex, redir->src_file);
	}

}

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
