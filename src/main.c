/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 17:18:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_args.h"

int	main(int ac, char **av, char **envp)
{
	ft_setup_prog((const char *const *)av);
	return (mini_main(ac, av, envp));
}
