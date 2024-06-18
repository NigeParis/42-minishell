/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:59 by iron              #+#    #+#             */
/*   Updated: 2023/12/30 12:58:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_dl_clear(t_dlist **head, t_data_apply del)
{
	size_t	ret;

	ret = ft_dl_delete_range(*head, NULL, del);
	*head = NULL;
	return (ret);
}

size_t	ft_dl_clear_range(t_dlist *start, t_dlist *end, t_data_apply del)
{
	size_t	i;

	i = 0;
	if (start == NULL)
		return (0);
	while (start != end)
	{
		if (del)
			del(start->data);
		start->data = NULL;
		start = start->next;
		i++;
	}
	return (i);
}
