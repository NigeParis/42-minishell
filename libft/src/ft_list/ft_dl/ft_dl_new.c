/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:42:00 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:42:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_dlist	*ft_dl_new(void)
{
	t_dlist	*ret;

	ret = ft_calloc(1, sizeof(t_dlist));
	if (!ret)
		return (ret);
	ret->data = NULL;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}
