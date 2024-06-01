/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:58:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 20:04:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcnb(char *str, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == c)
			nb++;
	if (c == '\0')
		nb++;
	return (nb);
}
