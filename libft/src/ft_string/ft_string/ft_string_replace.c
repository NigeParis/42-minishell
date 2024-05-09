/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:23 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 18:48:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_replace(t_string *str, char *to_replace, char *replace_by)
{
	char	*tmp;
	char	*tmp2;

	tmp = str->str;
	tmp2 = ft_str_replace(tmp, to_replace, replace_by);
	if (tmp2 == NULL)
		return (0);
	ft_string_set(str, tmp2);
	free(tmp);
	free(tmp2);
	return (1);
}

int	ft_string_replace_chr(t_string *str, char to_replace, char replace_by)
{
	char	tmp[2][2];

	tmp[0][0] = to_replace;
	tmp[0][1] = '\0';
	tmp[1][0] = replace_by;
	tmp[1][1] = '\0';
	return (ft_string_replace(str, tmp[0], tmp[1]));
}
