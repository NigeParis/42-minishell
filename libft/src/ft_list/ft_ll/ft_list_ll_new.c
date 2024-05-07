/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:30:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 11:40:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	*ft_listnew(void)
{
	t_list	*elem;

	elem = ft_calloc(sizeof(t_list), 1);
	return (elem);
}
