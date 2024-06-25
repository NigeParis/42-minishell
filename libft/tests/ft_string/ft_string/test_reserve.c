/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_reserve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_reserve(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_reserve(str, 42);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 42)
		return (3);
	ft_string_destroy(&str);
	return (0);
}
