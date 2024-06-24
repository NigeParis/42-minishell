/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:01:02 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/24 13:06:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include "ft_char.h"
#include "ft_args.h"
#include "ft_string.h"
#define PATH_MAX 1024

static void  put_builtin_msg_invalid_option(const char *progname, t_cmd_to_exec *cmd)
{
    ft_putstr_fd(&progname[2], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putchar_fd(cmd->argv[1][0], STDERR_FILENO);
    ft_putchar_fd(cmd->argv[1][1], STDERR_FILENO);
    ft_putendl_fd(": invalid option", STDERR_FILENO);
    ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd("usage: ", STDERR_FILENO);
    ft_putendl_fd(cmd->argv[0], STDERR_FILENO);
}

char   *get_pwd(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
    (void)ctrl;
    char buff[PATH_MAX];
    char *res;
    const char *progname = ft_progname();
    
    if ((cmd->ac > 1) && (ft_strcmp(cmd->argv[1], "-") != 0) \
        && (ft_strlen(cmd->argv[1]) > 1))
    {
        if (cmd->argv[1][0] != '-' || (ft_strlen(cmd->argv[1]) == 2 \
            && cmd->argv[1][1] == '-'))
            ;
        else
        {
            put_builtin_msg_invalid_option(progname, cmd);
            return (NULL);
        }
    }
    res = getcwd(buff, PATH_MAX);
    if (!res)
        return (NULL);
    ft_putendl_fd(res, STDOUT_FILENO);
    return (res);
}
