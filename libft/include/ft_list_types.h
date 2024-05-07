/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:37:44 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:09:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_TYPES_H
# define FT_LIST_TYPES_H

# include <stdbool.h>
# define FTLIST_SUCCESS 0
# define FTLIST_FAILURE 1

/// @brief Structure representing a node in a list
/// @param data The data of the node
/// @param next The next node
typedef struct s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

/// @brief Structure representing a node in a doubly linked list
/// @param data The data of the node
/// @param next The next node
/// @param prev The previous node
typedef struct s_dl_list
{
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
	void				*data;
}						t_dlist;

/// @brief Type of function to apply on a node data
typedef void			(*t_data_apply)(void *);

/// @brief Type of function to apply on a doubly linked list node
typedef void			(*t_dnode_apply)(t_dlist *);

/// @brief Type of function to apply on a simply linked list node
typedef void			(*t_lnode_apply)(t_list *);

/// @brief Type of function to see if a node data is something
typedef bool			(*t_data_is)(const void *);

#endif /* FT_LIST_TYPES_H */
