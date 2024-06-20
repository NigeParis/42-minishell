/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:57:42 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/20 16:58:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void test_first_cmd(t_cmd_to_exec *args, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[0],str) == 0)
    {
        *args = *(*f)();   
        if (!cmds[1])
            args->lastcmd_index = LAST_CMD;
        else
            args->lastcmd_index = FIRST_CMD;
    } 
}


void test_pipe_cmd(t_cmd_to_exec *args, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[1],str) == 0)
    {
        *args = *(*f)();   
        if (!cmds[2])
            args->lastcmd_index = LAST_CMD;
        else
            args->lastcmd_index = PIPE_CMD;
    }   
}


void test_last_cmd(t_cmd_to_exec *args, char *cmds[], char *str, t_cmd_to_exec *(*f)(void))
{

    if (ft_strcmp(cmds[2],str) == 0)
    {
        *args = *(*f)();   
        if (!cmds[3])
            args->lastcmd_index = LAST_CMD;
        else
            args->lastcmd_index = LAST_CMD;
    }   
}

