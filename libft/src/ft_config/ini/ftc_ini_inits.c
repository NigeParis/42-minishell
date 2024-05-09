/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_ini_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:19:37 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 11:22:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "internal/ft_config_ini.h"
#include <stdbool.h>
#include <stddef.h>

void	*ftc_ini_core_init(void)
{
	t_inifile	*ret;

	ret = ft_calloc(sizeof(*ret), 1);
	if (!ret)
		return (ret);
	ret->com_inline = false;
	ret->com_token = '#';
	ret->arr_token = '|';
	ret->equ_token = '=';
	ret->dup_crash = true;
	ret->multi_line = false;
	ret->section_default = "global";
	ret->sections = NULL;
	ftc_ini_push_section(NULL, ret->section_default, ret);
	return ((void *)ret);
}

void	*ftc_ini_extended_init(void)
{
	t_inifile	*ret;

	ret = ftc_ini_core_init();
	if (!ret)
		return (ret);
	ret->com_inline = true;
	ret->dup_crash = false;
	return ((void *)ret);
}
