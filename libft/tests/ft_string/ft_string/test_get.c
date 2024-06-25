/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:21:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_get(void)
{
	t_string	*str;
	const char	*c_str;

	str = ft_string_from("Hello worlds!");
	c_str = ft_string_get(str);
	if (ft_strncmp(str->str, c_str, str->length) != 0)
		return (1);
	ft_string_destroy(&str);
	return (0);
}
