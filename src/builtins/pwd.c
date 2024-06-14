/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 10:56:03 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"

static void  put_builtin_msg_invalid_option(const char *progname, t_cmd *cmd)
{
    ft_putstr_fd(&progname[2], 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(cmd->args[0], 2);
    ft_putstr_fd(": ", 2);
    ft_putchar_fd(cmd->args[1][0], 2);
    ft_putchar_fd(cmd->args[1][1], 2);
    ft_putendl_fd(": invalid option", 2);
    ft_putstr_fd(cmd->args[0], 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd("usage: ", 2);
    ft_putendl_fd(cmd->args[0], 2);
}

char   *get_pwd(t_minishell_control *ctrl, t_cmd *cmd)
{
    (void)ctrl;
    char buff[PATH_MAX];
    char *res;
    const char *progname = ft_progname();
    
    if ((cmd->argc > 1) && (ft_strcmp(cmd->args[1], "-") != 0) \
        && (ft_strlen(cmd->args[1]) > 1))
    {
        if (cmd->args[1][0] != '-' || (ft_strlen(cmd->args[1]) == 2 \
            && cmd->args[1][1] == '-'))
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
    ft_putendl_fd(res, 1);
    return (res);
}


