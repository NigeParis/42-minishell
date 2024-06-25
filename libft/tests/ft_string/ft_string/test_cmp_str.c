/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_cmp_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_cmp_str(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from("Hello");
	if (ft_string_cmpstr(str, str2) != 0)
		return (1);
	ft_string_destroy(&str2);
	str2 = ft_string_from("Hello World");
	if (ft_string_cmpstr(str, str2) >= 0)
		return (2);
	ft_string_destroy(&str2);
	str2 = ft_string_from("Hell");
	if (ft_string_cmpstr(str, str2) <= 0)
		return (3);
	ft_strlen(str2->str);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (0);
}
