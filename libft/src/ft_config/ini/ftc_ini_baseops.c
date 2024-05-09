/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_ini_baseops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:55:44 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 11:41:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"
#include "internal/ft_config_ini.h"
#include "ft_string.h"
#include <fcntl.h>

static int loc_kv_delc(const char *str, t_inifile *file)
{
	const char *eq_pos = ft_strchr(str, file->equ_token);
	const char *com_pos = ft_strchr(str, file->com_token);
	char *key;
	char *tmp;
	char *value;

	if (str == eq_pos || eq_pos == NULL || com_pos == eq_pos || \
	ft_strrchr(eq_pos + 1, file->equ_token) != eq_pos && \
	(!com_pos || ft_strrchr(eq_pos + 1, file->equ_token) > com_pos))
		return (1);
	key = ft_strndup(str, eq_pos - str);
	value = ft_strndup(eq_pos + 1, ft_min(com_pos, ft_strlen(eq_pos + 1)));
	tmp = ft_strtrim(key, " \t\n");
	free(key);
	key = tmp;
	tmp = ft_strtrim(value, " \t\n");
	free(value);
	value = tmp;
	return (ftc_ini_push_kv(key, value, file));
}

static int loc_section_delc(char *str, t_inifile *file)
{
	const char	*section_start = ft_strchr(str, '[');
	const char	*section_end = ft_strchr(section_start, ']');
	t_ini_section *to_push;
	char *section;
	char *parent;
	char *name;
	int ret;

	if (!section_end || section_start + 1 == section_end)
		return (1);
	section = ft_strndup(section_start + 1, (section_end - section_start) - 2);
	ftc_ini_extract_parandname(section, &name, &parent); // extract from section name the parent and the name
	if (!name || !parent)
		return (1);
	if (ftc_ini_get_section(name, file) != NULL) // section already exist
		return (free(section), 1);
	ret = ftc_ini_push_section(parent, name, file); // try to push section
	free(section);
	free(parent);
	free(name);
	return (ret); // send back the return of the push try
}

static int	loc_treat_str(const char *str, t_inifile *file)
{
	char c;
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	c = str[i];
	if (c == file->com_token)
		return (0);
	if (c == '[')
		return (loc_section_delc(str, file));
	return (loc_kv_delc(str, file));
}

int	ftc_ini_load(const char *file, void *content)
{
	const int	fd = open(file, O_RDONLY);
	const char	*str;

	if (fd < 0)
		return (1);
	str = ft_get_next_line(fd);
	while (str)
	{
		if (loc_treat_str(str, (t_inifile *)content))
			return (free(str), free_inifile(content), 1);
		free(str);
		str = ft_get_next_line(fd);
	}
	return (0);
}
int ftc_ini_savefiledump(int fd, t_inifile *params)
{
	return (1);
}

int ftc_ini_savesmart(int fd, t_inifile *params)
{
	return (1);
}

int	ftc_ini_save(const char *file, void *control_struct)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT | O_EXCL);
	if (fd > 0)
		return (ftc_ini_savefiledump(fd, control_struct));
	fd = open(file, O_WRONLY);
	if (fd > 0)
		return (ftc_ini_savesmart(fd, control_struct));
	return (1);
}
// key can be of form 
//  "section.key"
//  "sectionParentN...sectionParentN - 1.section.key"
//  "key" (can match "NotASection.key")
void	*ftc_ini_get(const char *key, void *control_struct)
{
	return (ftc_ini_get_k(key, (t_inifile *)control_struct));
}

int	ftc_ini_set(const char *key, void *value, void *control_struct)
{
	t_ini_node *node;

	node = ft_calloc(sizeof(*node), 1);
	ft_memcpy(node, value, sizeof(*node));
	return (ftc_ini_set_kv(key, value, (t_inifile *)control_struct));
}
