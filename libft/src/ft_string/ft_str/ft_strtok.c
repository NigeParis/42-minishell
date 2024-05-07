/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:19:26 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/31 18:00:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtok(char *str, const char *token)
{
	static char	*ptr;
	char		*ret;

	if (str)
		ptr = str;
	while (ptr && ft_strchr(token, *ptr) && *ptr)
		ptr++;
	ret = ptr;
	while (ptr && !ft_strchr(token, *ptr) && *ptr)
		ptr++;
	if (ptr && *ptr)
	{
		*ptr = 0;
		ptr++;
	}
	else
		ptr = 0;
	return (ret);
}
