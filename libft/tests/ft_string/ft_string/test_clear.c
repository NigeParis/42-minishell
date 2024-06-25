/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_clear(void)
{
	t_string	*str;
	size_t		capacity;

	str = ft_string_from("Hello");
	capacity = str->capacity;
	ft_string_clear(str);
	if (ft_string_cmp(str, "") != 0)
		return (1);
	if (str->length != 0)
		return (2);
	if (str->capacity != capacity)
		return (3);
	ft_string_destroy(&str);
	return (0);
}
