/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_inplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:56:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 13:55:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_string_set_inplace(void)
{
	t_string	*str;
	char		*src;
	const char	*res;

	src = ft_strdup("Hello world this is zod!");
	str = ft_string_new(0);
	ft_string_set_inplace(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (1);
	ft_string_destroy(&str);
	return (0);
}
