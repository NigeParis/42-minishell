/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/02 18:06:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"

void ft_optional_copy(t_optional *dest, t_optional *src)
{
	dest->pres = src->pres;
	dest->val = src->val;
}
