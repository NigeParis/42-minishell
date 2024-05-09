/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_baseop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:32:20 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/07 11:55:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"
#include "ft_string.h"

t_config	*ft_init_config(const char *filepath, t_ctype config_type)
{
	t_config	*ret;

	if (config_type == CTYPE_ERROR)
		return (NULL);
	ret = ft_calloc(sizeof(*ret), 1);
	if (ret == NULL)
		return (ret);
	ret->base_parser_f = ftc_parserby_type(config_type);
	ret->configtype = config_type;
	ret->filename = filepath;
	ret->content = ret->base_parser_f.init();
	return (ret);
}

int	ft_congig_load(t_config *config)
{
	return (config->base_parser_f.load(config->filename, config->content));
}

int	ft_congig_save(t_config *config)
{
	return (config->base_parser_f.save(config->filename, config->content));
}

void	*ft_congig_get(t_config *config)
{
	return (config->base_parser_f.get(config->filename, config->content));
}

int	ft_congig_set(t_config *config, const char *key, void *value)
{
	return (config->base_parser_f.load(config->filename, config->content));
}
