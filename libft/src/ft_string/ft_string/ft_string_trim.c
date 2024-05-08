/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 14:02:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdio.h>

void	ft_string_trim(t_string *str)
{
	return (ft_string_trimstr(str, " \t\n"));
}

void	ft_string_trim_chr(t_string *str, char c)
{
	const char	to_trim[2] = {c, '\0'};

	return (ft_string_trimstr(str, (char *)to_trim));
}

// placing the null terminator at the end of the string
// because str->str is not reset after.
void	ft_string_trimstr(t_string *str, char *to_trim)
{
	size_t	rpad;
	size_t	lpad;

	lpad = 0;
	if (!to_trim || !str || !str->str || str->length == 0)
		return ;
	while (ft_strchr(to_trim, str->str[lpad]) != NULL && lpad < str->length)
		lpad++;
	rpad = str->length - 1;
	while (ft_strchr(to_trim, str->str[rpad]) != NULL && rpad > 0)
		rpad--;
	if (rpad < lpad)
		return ((void) ft_string_set(str, ""));
	ft_memmove(str->str, str->str + lpad, rpad - lpad + 1);
	str->length = rpad - lpad + 1;
	str->str[str->length] = '\0';
}
