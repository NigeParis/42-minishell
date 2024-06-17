/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/17 14:25:39 by nrobinso         ###   ########.fr       */
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

void	ft_open_outfile(t_pipex *pipex, char *outfile)
{
	if (checkfile_read_and_exists(outfile, OUTFILE))
	{	
		pipex->fdout = open(outfile, O_WRONLY | O_TRUNC, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror("outfile");
			exit (0);
		}
	}
	else
	{
		pipex->fdout = open(outfile, O_WRONLY | O_CREAT, 0755);
		if (pipex->fdout == -1)
		{
			close_fdout(pipex);
			perror("outfile");
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
			perror("infile");
			exit (0);
		}
	}
}


int	execute(t_cmd_to_exec *args,  t_pipex *pipex, t_redir *redir)
{
	static int i = 0;
	i++;
	
	if ((args->right_token == '>') && (args->lastcmd_index == LAST_CMD))
		redir->dst_flag = 1;

	if ((args->left_token == '<') && (args->lastcmd_index == FIRST_CMD))
		redir->src_flag = 1;

	if (redir->dst_flag > 0)
	{
		ft_open_outfile(pipex, redir->file_dst);
	}
	if (redir->src_flag > 0)
	{
		ft_open_infile(pipex, redir->file_src);
	}
	ft_pipes(pipex, args, redir, i);
	
	if (args->lastcmd_index == LAST_CMD)
		waitpid(pipex->child_pid, &args->status, 0);
	return (0);
}
