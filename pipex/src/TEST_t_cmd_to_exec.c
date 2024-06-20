/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_t_cmd_to_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:04:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/20 16:12:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


//FIRST

t_cmd_to_exec    *cmd_to_exec_pwd(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/pwd");
    blank->argv = ft_split("pwd", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_exit(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("exit");
    blank->argv = ft_split("exit 12", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}







t_cmd_to_exec    *cmd_to_exec_ls_l(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/ls");
    blank->argv = ft_split("ls -l", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    ft_ll_push(&blank->redir_to_do, test_redir());
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}



t_cmd_to_exec    *cmd_to_exec_ls(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/ls");
    blank->argv = ft_split("ls", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_qqqq(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = NULL;
    blank->argv = ft_split("", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_yes(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/yes");
    blank->argv = ft_split("yes", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_echo(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/echo");
    blank->argv = ft_split("echo hello", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

// SECOND CMD


t_cmd_to_exec    *cmd_to_exec_cat_e(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/cat");
    blank->argv = ft_split("cat -e", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = '|';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_cat(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/cat");
    blank->argv = ft_split("cat", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = '|';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_echo_n(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/echo");
    blank->argv = ft_split("echo -n Hello", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_wc(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/wc");
    blank->argv = ft_split("wc", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    //ft_ll_push(&blank->redir_to_do, test_redir());
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


// LAST CMD


// t_cmd_to_exec    *cmd_to_exec_cat_last(void)
// {
//     t_cmd_to_exec    *blank;

//     blank = malloc(sizeof(t_cmd_to_exec));
//     if (!blank)
//         return (NULL);
//     blank->cmd_path = ft_strdup("/usr/bin/cat");
//     blank->argv = ft_split("cat", ' ');
//     blank->ac = ft_len_2d((const void * const *)blank->argv);
//     blank->env = NULL;
//     blank->status = 0;
//     blank->redir_to_do = NULL;
//     blank->lastcmd_index = LAST_CMD;
//     blank->left_token = ' ';
//     blank->right_token = ' ';
//     return (blank);
// }