/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_replace(void)
{
	t_string	*str;

	str = ft_string_from("Hello worlds!");
	ft_string_replace(str, "worlds", "Worlds");
	if (ft_string_cmp(str, "Hello Worlds!"))
		return (1);
	ft_string_append(str, " Worlds!");
	ft_string_replace(str, "Worlds", "earth");
	if (ft_string_cmp(str, "Hello earth! earth!"))
		return (2);
	ft_string_destroy(&str);
	return (0);
}
