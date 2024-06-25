/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_t_str_replace_chr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:21:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	test_string_replace_chr(void)
{
	t_string	*str;

	str = ft_string_from("Hello worlds!");
	ft_string_replace_chr(str, 'o', 'O');
	if (ft_string_cmp(str, "HellO wOrlds!"))
		return (1);
	ft_string_destroy(&str);
	return (0);
}
