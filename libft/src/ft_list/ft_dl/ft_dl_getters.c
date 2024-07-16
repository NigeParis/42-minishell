/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:21 by iron              #+#    #+#             */
/*   Updated: 2023/12/10 12:44:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

void	**ft_dl_get_datas(const t_dlist *src)
{
	size_t	size;
	void	**ret;

	if (!src)
		return (NULL);
	size = ft_dl_size(src);
	ret = malloc(sizeof(void *) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	size = 0;
	while (src)
	{
		ret[size++] = (void *)src->data;
		src = src->next;
	}
	return (ret);
}

t_dlist	**ft_dl_get_nodes(const t_dlist *src)
{
	size_t	size;
	t_dlist	**ret;

	size = ft_dl_size(src);
	ret = NULL;
	if (!src)
		return (NULL);
	ret = malloc(sizeof(t_dlist *) * (size + 1));
	if (!ret)
		return (ret);
	ret[size] = NULL;
	size = 0;
	while (src)
	{
		ret[size++] = (t_dlist *)src;
		src = src->next;
	}
	return (ret);
}
