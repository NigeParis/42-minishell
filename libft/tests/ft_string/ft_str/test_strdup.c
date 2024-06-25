/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:23:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:10:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strdup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strdup(str);
	if (ft_strcmp(res, str) != 0)
		return (1);
	free(res);
	return (0);
}
