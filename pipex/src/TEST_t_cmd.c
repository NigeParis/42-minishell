/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:26:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/20 13:58:06 by nrobinso         ###   ########.fr       */
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





//TESTS ECHO
/*
echo hello    world                 // gestion extra spaces by Baptiste
echo "hello   world"                // "    " gestion by Baptiste
echo ce test vas marcher
echo -n pas de retour a la ligne
echo -nnnnnnnnn rien a dire
echo -nnnnn -n -n -nnnn bizare mais OK
echo -nnnnn -nnnnnnm carrement chelouuuu
echo -nnnnn -nnnnnnm tordu -n hello
*/

t_cmd    *test_cmd_echo(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("echo");
	testcmd->args = ft_split("echo hello", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;
	testcmd->lastcmd_index = FIRST_CMD;

    return (testcmd);
}



t_cmd    *test_cmd_exit(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("exit");
	testcmd->args = ft_split("exit 1", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;
	testcmd->lastcmd_index = PIPE_CMD;

    return (testcmd);
}

