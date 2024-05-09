/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:46:59 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/09 13:29:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_toggle_char(char *str[], char c, int toggle)
{
    ft_tog_delim_ch(*str, '\'', c, toggle);  
//    ft_tog_delim_ch(str, '\"', c, toggle);  
     
}

void    ft_tog_delim_ch(char *str, char delimiter, char c, int toggle)
{
    int count[2];
    int fst_pos;
    int lst_pos;

    count[0] = 0;
    count[1] = 0;
    if (toggle == 1)
        c = (c * -1);
    while (str && str[count[0]])
    {
        ft_find_delim(str, delimiter, count, &fst_pos);
        if (count[1] == 2)
        {
            lst_pos = count[0];
            count[0] = fst_pos + 1;
            while (fst_pos < lst_pos)
            {
                if (str[fst_pos] == c )
                {
                    str[fst_pos] = (c * -1);
                }
                fst_pos++;
            }
            count[1] = 0;
            count[0] = lst_pos;
        }
        count[0]++;
    }
}

void    ft_find_delim(char *str, char delimiter, int *count, int *fst_pos)
{
    if (str[count[0]] == delimiter)
    {
        if (count[1] == 0)
            *fst_pos = count[0];
        count[1] +=1;
    }
}

void	ft_make_toogle_cmd_arg(t_pipex *pipex)
{
	int	i;
	int j[2];
	
	i = 0;
	j[0] = 0;
	j[1] = 0;
	while (pipex->cmds && pipex->cmds[i])
	{
		ft_toggle_char(&pipex->cmds[i], ' ', 1);
		while (pipex->cmds[i][j[0]])
		{
			if (pipex->cmds[i][j[0]] == '\'' )
				j[0]++;
			if (pipex->cmds[i][j[0]] != '\0')	
				pipex->cmds[i][j[1]++] = pipex->cmds[i][j[0]++];
			else
				break ;	
		}
		pipex->cmds[i][j[1]] = '\0';
		while (j[1] < j[0])
			pipex->cmds[i][j[1]++] = '\0';
		j[0] = 0;
		j[1] = 0;
		i++;		
	}
}
