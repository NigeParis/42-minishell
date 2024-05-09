/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_ini_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:57:05 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 13:09:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "internal/ft_config_ini.h"
#include <stddef.h>

static int kv_cmp(t_ini_node *node1, char *name)
{
	return (ft_strcmp(node1->key, name));
}

static int section_cmp(t_ini_section *sec1, char *name)
{
	return (ft_strcmp(sec1->name, name));
}

t_ini_section	*ftc_ini_get_section(const char *s, t_inifile *file)
{
	t_ini_section	*ret;
	
	ret = (t_ini_section *)ft_listfind(file->sections, (void *)s, &section_cmp);
	return (ret);
}

void	*ftc_ini_get_k(const char *k, t_inifile *file)
{
	t_list *sect;
	t_ini_node *kv;

	// if string of key specify a section get section on that first;
	// if section not found search all section for match on basename
	sect = file->sections;
	kv = NULL;
	while (sect && !kv)
	{
		kv = ft_listfind(file->sections, (void *)k, &kv_cmp);
		sect = sect->next;
	}
	return (kv);
}
/*
** - [section1]
** - ok=truc
** - bidule=machin
** - [section2]
** - ok=truc2
** - key=42
*/