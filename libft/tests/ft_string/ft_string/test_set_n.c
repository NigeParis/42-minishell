/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_set_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:57:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 13:12:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_string_set_n(void)
{
	t_string	*str;
	const char	*src;
	const char	*res;

	src = "Hello world this is zod!";
	str = ft_string_new(0);
	ft_string_set_n(str, src, 6);
	res = ft_string_get(str);
	if (ft_strcmp("Hello", res) != 0)
		return (1);
	ft_string_destroy(&str);
	return (0);
}
