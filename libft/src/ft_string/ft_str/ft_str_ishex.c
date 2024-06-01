/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ishex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:46:22 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:29:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"

bool	ft_str_ishex(const char *str)
{
	if (!str)
		return (0);
	if (ft_strstart_with(str, "0X") || ft_strstart_with(str, "0x"))
		str += 2;
	return (ft_str_isvalid(str, ft_ishexdigit));
}
