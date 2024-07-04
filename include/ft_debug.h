/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:27:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/04 12:28:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

#include "ft_list_types.h"
#include "parser_types.h"

void	print_redirs(t_list *redirs);
void	print_cmd(t_cmd_to_exec *cmd);

#endif // FT_DEBUG_H
