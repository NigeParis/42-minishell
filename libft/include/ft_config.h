/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:35:45 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/08 02:19:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONFIG_H
# define FT_CONFIG_H

# include "ft_list_types.h"
# include <stddef.h>

typedef enum e_type
{
	CTYPE_INI_CORE,
	CTYPE_INI_EXTENDED,
	CTYPE_CUSTOM,
	CTYPE_ERROR
}							t_ctype;

typedef struct s_suffix_table
{
	const char				*suffix;
	t_ctype					ctype;
}							t_suffix_table;

typedef struct s_obj_parser_type
{
	t_ctype	type;
	void	*(*init)(void);
	int		(*load)(const char *file, void *control_struct);
	int		(*save)(const char *file, void *control_struct);
	void	*(*get)(const char *key, void *control_struct);
	int		(*set)(const char *key, void *value, void *control_struct);
}			t_obj_parser_type;

// takes -> content;
//	char	*(*strerror)() translate errors of module ? idk
// suplementary function for specific types such as JSON_TREE can be made
//   separately to act on content on their own

// init
// load
// save
// get
// set
// strerr

typedef struct s_config
{
	const char				*filename;
	t_ctype					configtype;
	void					*content;
	t_obj_parser_type		base_parser_f;
}							t_config;
//	int						fd;
// dumb will handle fd inside load func to allow read only on local func

// returns null config_type is invalid.
t_config					*ft_init_config(const char *filepath,
								t_ctype config_type);
t_obj_parser_type			ftc_parserby_type(t_ctype type);
t_obj_parser_type			ftc_parserby_suffix(const char *suffix);

// ok = 0 err = 1
int							ft_config_init(t_config conf);
int							ft_config_load(t_config conf);
int							ft_config_save(t_config conf);
void						*ft_config_get(t_config conf, const char *key);
int							ft_config_set(t_config conf, const char *key,
								void *value);

#endif // FT_CONFIG_H
