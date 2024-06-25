/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:16:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_to_str(void)
{
	t_string	*str;
	char		*cstr;

	str = ft_string_from("Hello World");
	cstr = ft_string_to_str(str);
	if (ft_strcmp(cstr, "Hello World") != 0)
		return (1);
	ft_string_destroy(&str);
	free(cstr);
	return (0);
}
