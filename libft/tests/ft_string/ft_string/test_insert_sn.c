/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_insert_sn.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_insert_sn(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World!!!!");
	ft_string_insert_s_n(str, str2, 0, 5);
	if (ft_string_cmp(str, " WorlHello") != 0)
		return (1);
	if (str->length != 10)
		return (2);
	if (str->capacity < 10)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}
