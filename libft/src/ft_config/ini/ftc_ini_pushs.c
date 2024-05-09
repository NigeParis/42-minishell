/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_ini_pushs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:54 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 11:43:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "internal/ft_config_ini.h"
#include <stdbool.h>
#include <stddef.h>

int	ftc_ini_push_kv(const char *k, const char *v, t_inifile *file)
{
	t_ini_section	*sec;
	t_ini_node		*kv_node;
	t_list			*elem;

	kv_node = ft_calloc(sizeof(*kv_node), 1);
	if (!kv_node)
		return (1);
	sec = (t_ini_section *)file->sections->content;
	kv_node->key = k;
	kv_node->value = v;
	kv_node->array = false;
	kv_node->parent = sec;
	elem = ft_listnew(kv_node);
	if (!elem)
		return (1);
	ft_listadd_back(&(sec->kv_pairs), elem);
	return (0);
}

int	ftc_ini_push_secion(const char *parent, const char *s, t_inifile *file)
{
	t_ini_section	*section;
	t_list			*elem;
	char			*parent;
	char			*lst;

	section = ft_calloc(sizeof(*section), 1);
	if (!section)
		return (1);
	section->name = s;
	section->parent = ftc_ini_get_section(parent, file);
	section->kv_pairs = NULL;
	elem = ft_listnew(section);
	if (!elem)
		return (1);
	ft_listadd_front(&file->sections, elem);
	return (0);
}
