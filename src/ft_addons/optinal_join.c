/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optinal_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 08:35:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/22 08:35:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional_types.h"
#include "ft_string.h"

char *optional_strjoin(t_optional *str1, t_optional *str2)
{
	if (str1->pres == OPT_NONE && str2->pres == OPT_NONE)
		return (NULL);
	if (str1->pres == OPT_NONE)
		return (ft_strdup(str2->val));
	if (str2->pres == OPT_NONE)
		return (ft_strdup(str1->val));
	return (ft_strjoin(str1->val, str2->val));
}
