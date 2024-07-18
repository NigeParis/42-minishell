/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_buff_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:48:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:51:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <unistd.h>

void	buff_print_all(void)
{
	print_buff(STDIN_FILENO);
	print_buff(STDOUT_FILENO);
	print_buff(STDERR_FILENO);
}

void	buff_destroy_all(void)
{
	destroy_buff(STDIN_FILENO);
	destroy_buff(STDOUT_FILENO);
	destroy_buff(STDERR_FILENO);
}
