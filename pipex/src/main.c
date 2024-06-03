/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 11:22:58 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "pipex.h"





void	ft_free_tab(char *tab)
{
	if (tab)
		free (tab);
}



int	main(int argc, char *argv[], char *env[])
{
	for (int i = 0; argv[i]; i++)
		printf("[%d] %s\n", i, argv[i]);

	return(pipex(argc, argv, env));
}
