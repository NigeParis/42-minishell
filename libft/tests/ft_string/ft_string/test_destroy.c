/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 17:37:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

/*
	ft_string_destroy(&str); // null resiliancy
	ft_string_destroy(NULL); // null resiliancy
*/
int	test_string_destroy(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_destroy(&str);
	if (str != NULL)
		return (1);
	ft_string_destroy(&str);
	ft_string_destroy(NULL);
	return (0);
}
