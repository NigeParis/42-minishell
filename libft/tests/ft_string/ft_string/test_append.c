/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_append(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_append(str, " World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	return (0);
}
