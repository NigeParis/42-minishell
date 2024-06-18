/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:26:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/18 11:28:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


t_cmd    *test_cmd_pwd(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("pwd");
	testcmd->args = ft_split("pwd", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}


t_cmd    *test_cmd_echo(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("echo");
	testcmd->args = ft_split("echo hello *", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}



t_cmd    *test_cmd_exit(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("exit");
	testcmd->args = ft_split("exit 127", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}