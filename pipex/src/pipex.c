/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/05 18:24:48 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int 	checkfile_read_and_exists(char *file)
{
	if (access(file, F_OK) == -1)
	{
		perror(file);
		return (0);
	}
	else if (access(file, W_OK) == -1)
	{
		perror(file);
		return (0);
	}
	return(1);
}


void	ft_open_files(t_pipex *pipex, char *outfile)
{
	if (checkfile_read_and_exists(outfile))
	{
		
		pipex->fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0755);
		if (pipex->fdout == -1)
		{
			close_fd(pipex);
			perror("outfile");
			exit (0);
		}
	}
	else
	{
		printf("Error create a file called \'file\'\n");

	}



}


int	execute(t_cmd_to_exec *args,  t_pipex *pipex, t_redir *redir)
{
	static int i = 0;
	i++;
	
	if (args->left_token == ';' && args->right_token == ';')
		i = args->lastcmd_index;
	if (args->right_token  == '|' && args->left_token == '|')
	{
		printf("-%s--->%d    %s\n",args->cmd_path, i, args->argv[0]);
		i = 2;
		ft_putstr_fd("HERE", 1);
	}
	if (redir->flag > 0)
	{
		ft_open_files(pipex, redir->target_file);
	}
	ft_pipes(pipex, args, redir, i);

	while (wait(NULL) > 0)
		;
	return (0);
}
