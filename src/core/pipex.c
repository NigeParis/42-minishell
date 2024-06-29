/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/29 11:54:00 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(t_cmd_to_exec *cmd, t_pipex *pipex, t_minishell_control *shell)
{
	
	make_pipe(pipex, cmd, shell);
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
