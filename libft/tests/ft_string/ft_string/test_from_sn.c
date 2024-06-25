/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_from_sn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:28:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_from_sn(void)
{
	t_string	*str;
	t_string	*str_src;

	str_src = ft_string_from("Hello World");
	str = ft_string_from_s_n(str_src, 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 5)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str_src);
	return (0);
}
