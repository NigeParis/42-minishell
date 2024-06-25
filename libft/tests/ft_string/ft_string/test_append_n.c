/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_append_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_append_n(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_append_n(str, " World", 5);
	if (ft_string_cmp(str, "Hello Worl") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	return (0);
}
