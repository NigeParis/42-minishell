/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:57:42 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/25 10:37:53 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void test_first_cmd(t_cmd_to_exec *cmd, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[0],str) == 0)
    {
        *cmd = *(*f)();   
        if (!cmds[1])
            cmd->lastcmd_index = LAST_CMD;
        else
            cmd->lastcmd_index = FIRST_CMD;
    } 
}


void test_pipe_cmd(t_cmd_to_exec *cmd, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[1],str) == 0)
    {
        *cmd = *(*f)();   
        if (!cmds[2])
            cmd->lastcmd_index = LAST_CMD;
        else
            cmd->lastcmd_index = PIPE_CMD;
    }   
}


void test_last_cmd(t_cmd_to_exec *cmd, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[2],str) == 0)
    {
        *cmd = *(*f)();   
        if (!cmds[3])
            cmd->lastcmd_index = LAST_CMD;
        else
            cmd->lastcmd_index = LAST_CMD;
    }   
}

