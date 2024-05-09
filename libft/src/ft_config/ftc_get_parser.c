/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_get_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:59:47 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/07 13:52:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_config_ini.h"
#include "ft_config.h"
#include "ft_string.h"

t_obj_parser_type	ftc_parserby_type(t_ctype type)
{
	const t_obj_parser_type	truth_table_parser[] = {\
	{CTYPE_INI_CORE, &ftc_ini_core_init, &ftc_ini_load, &ftc_ini_save, \
	&ftc_ini_get, &ftc_ini_set}, \
	{CTYPE_INI_EXTENDED, &ftc_ini_extended_init, &ftc_ini_load, &ftc_ini_save, \
	&ftc_ini_get, &ftc_ini_set}, \
	{CTYPE_ERROR, NULL, NULL, NULL, NULL, NULL} \
	};
	int						i;

	i = 0;
	while (truth_table_parser[i].type != type)
		i++;
	return (truth_table_parser[i]);
}

t_obj_parser_type	ftc_parserby_suffix(const char *suffix)
{
	const t_suffix_table	table[] = {\
	{".INI", CTYPE_INI_CORE},
	{".ini", CTYPE_INI_CORE},
	{".INIX", CTYPE_INI_EXTENDED},
	{".inix", CTYPE_INI_EXTENDED},
	{".config", CTYPE_CUSTOM},
	{NULL, CTYPE_ERROR}
	};
	int						i;

	i = 0;
	while (table[i].suffix)
		if (ft_strncmp(table[i++].suffix, suffix, ft_strlen(suffix)) == 0)
			return (ftc_parserby_type(table[--i].ctype));
	return (ftc_parserby_type(CTYPE_ERROR));
}
