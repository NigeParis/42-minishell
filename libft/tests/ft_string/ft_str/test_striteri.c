/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:39:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:10:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	local_iteri(unsigned int i, char *c)
{
	*c = 'a';
	(void)i;
}

int	test_striteri(void)
{
	char	str[20];

	ft_strlcpy(str, "Hello World!", 20);
	ft_striteri(str, &local_iteri);
	if (ft_strcmp(str, "aaaaaaaaaaaa") != 0)
		return (1);
	return (0);
}
