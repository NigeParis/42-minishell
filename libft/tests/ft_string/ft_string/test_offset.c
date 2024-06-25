/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_offset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 13:31:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_offset(void)
{
	t_string	*str;
	const char	*src;
	char		c;

	src = "Hello world this is zod!";
	str = ft_string_from(src);
	c = 'z';
	if (ft_string_offset(str, c) != 20)
		return (1);
	c = '!';
	if (ft_string_offset(str, c) != 23)
		return (2);
	c = '@';
	if (ft_string_offset(str, c) != -1)
		return (4);
	ft_string_destroy(&str);
	return (0);
}
