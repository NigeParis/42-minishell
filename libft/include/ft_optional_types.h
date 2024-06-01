/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_types.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:23 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:47:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONAL_TYPES_H
# define FT_OPTIONAL_TYPES_H

# include <stddef.h>

typedef enum e_optional_type
{
	OPT_NONE,
	OPT_SOME,
}				t_optional_type;

typedef struct s_optional
{
	t_optional_type	pres;
	void			*val;
}				t_optional;

#endif /* FT_OPTIONAL_TYPES_H */
