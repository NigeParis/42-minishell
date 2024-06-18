/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:40:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/27 10:05:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ft_list_types.h"
# include "ft_defs.h"

/* ************************************************************************** */
/*                           DOUBLY LINKED LIST                               */
/* ************************************************************************** */

// ft_list/ft_dl_add.c

/// @brief Add a node at the end of the list
/// @param head The head of the list
/// @param added The node to add
void	ft_dl_add_back(t_dlist **head, t_dlist *const added);

/// @brief Add a node at the beginning of the list
/// @param head The head of the list
/// @param added The node to add
void	ft_dl_add_front(t_dlist **head, t_dlist *const added);

// ft_list/ft_dl_apply.c

/// @brief Apply a function on every node of the list
/// @param start The start of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply(const t_dlist *start, t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply_range(const t_dlist *start, const t_dlist *end,
			t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply_range_node(const t_dlist *start, const t_dlist *end,
			t_dnode_apply applied);

// ft_list/ft_dl_clear.c

/// @brief Clear a list
/// @param head The adress of head of the list to clear
/// @param del The function to delete the data
/// @return The number of nodes deleted
/// @note The head is set to NULL
size_t	ft_dl_clear(t_dlist **head, t_data_apply del);

/// @brief Clear a list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param del The function to delete the data
/// @return The number of nodes deleted
size_t	ft_dl_clear_range(t_dlist *start, t_dlist *end, t_data_apply del);

// ft_list/ft_dl_create.c

/// @brief Create a new node
/// @param data The data of the node
/// @return The new node
t_dlist	*ft_dl_create(const void *data);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr
t_dlist	*ft_dl_copy_node(const t_dlist *const other);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr. This is wgy it doesn't need a delete function.
t_dlist	*ft_dl_copy_list(const t_dlist *const other);

// ft_list/ft_dl_delete.c

/// @brief Delete a node
/// @param node The node to delete
/// @param del The function to delete the data
/// @return The number of nodes deleted
int		ft_dl_delete_self(t_dlist *node, t_data_apply del);

/// @brief Delete a node
/// @param start The node from which to delete
/// @param end The node until which to delete
/// @return The number of nodes deleted
size_t	ft_dl_delete_range(t_dlist *start, const t_dlist *target,
			t_data_apply del);

/// @brief Delete a doubly linked list entirely
/// @param head The head of the list
/// @return The number of nodes deleted
size_t	ft_dl_delete(t_dlist **head, t_data_apply del);

// TODO: implement delete dup for dl
// not currently implemented - idea of the function:
// /// @brief Delete duplicates node
// /// @param head The head of the list
// /// @param cmp The compare function
// /// @param del The function to delete the data
// /// @return The number of nodes deleted
// size_t	ft_dl_delete_dup(t_dlist **src, t_data_cmp cmp,
//  			t_data_apply del);
//

// ft_list/ft_dl_find.c

/// @brief Find a node in a list
/// @param head The head of the list
/// @param data The data to find
/// @param cmp The compare function
/// @return The node found or NULL
t_dlist	*ft_dl_find(const t_dlist *head, const void *data, t_data_cmp cmp);

// ft_list/ft_dl_getters.c

/// @brief Get the datas of a list
/// @param src The list
/// @return The datas of the list
/// @note The datas are in the same order as the nodes and the pointers to the
/// datas need to be freed
void	**ft_dl_get_datas(const t_dlist *src);

/// @brief Get the nodes of a list
/// @param src The list
/// @return The nodes of the list
/// @note The nodes are in the same order as the datas and the pointers to the
/// nodes need to be freed
t_dlist	**ft_dl_get_nodes(const t_dlist *src);

// ft_list/ft_dl_iterator.c

/// @brief Get the last node of a list
/// @param head The head of the list
/// @param index The index of the node
/// @return The node at index or NULL
t_dlist	*ft_dl_at(const t_dlist *head, size_t index);

/// @brief Get the last node of a list
/// @param head The head of the list
/// @return The last node of the list
t_dlist	*ft_dl_end(const t_dlist *head);

/// @brief Get the first node of a list
/// @param head The head of the list
/// @return The first node of the list
t_dlist	*ft_dl_begin(const t_dlist *head);

// ft_list/ft_dl_map.c

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @param del The function to delete the data if allocation fails
/// @return The new list
t_dlist	*ft_dl_map(const t_dlist *lst, t_data_tr f, t_data_apply del);

// ft_list/ft_dl_new.c

/// @brief Create a new node
/// @return The new node
t_dlist	*ft_dl_new(void);

// ft_list/ft_dl_pushpop.c

/// @brief Push a node at the beginning of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_dlist	*ft_dl_push(t_dlist **node, const void *data);

/// @brief Push a node at the end of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_dlist	*ft_dl_push_back(t_dlist **node, const void *data);

/// @brief Pop a node at the beginning of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_dl_pop(t_dlist **node);

/// @brief Pop a node at the end of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_dl_pop_back(t_dlist **node);

// ft_list/ft_dl_rev.c

/// @brief Reverse a list
/// @param head The head of the list
/// @return the new head of the list
t_dlist	*ft_dl_rev(t_dlist **head);

// ft_list/ft_dl_size.c

/// @brief Get the size of a list
/// @param head The head of the list
/// @return The size of the list
size_t	ft_dl_size(const t_dlist *head);

/// @brief Get the size of a list
/// @param head The head of the list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_dl_size_of_data(const t_dlist *head, t_data_is function);

// ft_list/ft_dl_sub.c

/// @brief Get a sublist of a list
/// @param src The list
/// @param to The node until which to get the sublist
/// @return The sublist
/// @note The sublist is a copy of the original list but does not copy
/// the data in a new ptr. This is why it doesn't need a delete function.
t_dlist	*ft_dl_subrange(const t_dlist *src, const t_dlist *to);

/* ************************************************************************** */
/*                           SIMPLY LINKED LIST                               */
/* ************************************************************************** */

// ft_list/ft_list_ll_add.c

/// @brief Add a node at the begining of the list
/// @param head The head of the list
/// @param added The node to add
/// @return void
void	ft_ll_add_front(t_list **lst, t_list *const new_node);

/// @brief Add a node at the end of the list
/// @param head The head of the list
/// @param added The node to add
/// @return void
void	ft_ll_add_back(t_list **lst, t_list *const new_node);

// ft_list/ft_list_ll_apply.c

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @return void
void	ft_ll_apply(const t_list *lst, t_data_apply f);

/// @brief Apply a function on every node of the list until the element end
/// @param lst The list
/// @param end The end of the list
/// @param f The function to apply
/// @return void
void	ft_ll_apply_range(const t_list *lst, const t_list *end,
			t_data_apply f);

/// @brief Apply a function on every node of the list until the element end
/// @param lst The list
/// @param end The end of the list
/// @param f The function to apply
/// @return void
void	ft_ll_apply_range_node(const t_list *lst, const t_list *end,
			t_lnode_apply f);

// ft_list/ft_list_ll_clear.c

/// @brief Clear a list
/// @param lst The list
/// @param del The function to delete the data
/// @return void
void	ft_ll_clear(t_list **lst, t_data_apply del);

// TODO: implement clear range for ll

// ft_list/ft_list_ll_create.c

/// @brief Create a new node
/// @param data The data of the node
/// @return The new node
t_list	*ft_ll_create(const void *const data);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
t_list	*ft_ll_copy_node(const t_list *const other);

/// @brief Copy a list
/// @param other The list to copy
/// @return The new list
t_list	*ft_ll_copy_list(const t_list *const other);

// ft_list/ft_list_ll_delete.c

/// @brief Delete a node
/// @param node The node to delete
/// @param del The function to delete the data
/// @return void
void	ft_ll_delone(t_list *lst, t_data_apply del);

/// @brief Delete a node
/// @param lst The node from which to delete
/// @param target The node until which to delete
/// @param del The function to delete the data
/// @return void
size_t	ft_ll_delete_range(t_list *lst, const t_list *end, t_data_apply del);

// TODO: implement delete for ll
// delete should delete the whole list

// TODO: implement delete dup for ll
// not currently implemented - idea of the function:
// /// @brief Delete duplicates node
// /// @param head The head of the list
// /// @param cmp The compare function
// /// @param del The function to delete the data
// /// @return The number of nodes deleted
// size_t	ft_listdelete_dup(t_list **src, t_data_cmp cmp,
//  			t_data_apply del);

// ft_list/ft_list_ll_find.c

/// @brief Find a node in a list
/// @param list The list
/// @param data The data to find
/// @param cmp The compare function
/// @return The node found or NULL
void	*ft_ll_find(const t_list *list, const void *data, t_data_cmp cmp);

// ft_list/ft_list_ll_getters.c

/// @brief Get the datas of a list
/// @param src The list
/// @return The datas of the list
void	**ft_ll_get_datas(const t_list *src);

/// @brief Get the nodes of a list
/// @param src The list
/// @return The nodes of the list
t_list	**ft_ll_get_nodes(const t_list *src);

// ft_list/ft_list_ll_iterator.c

/// @brief Get the last node of a list
/// @param lst The list
/// @return The last node of the list
t_list	*ft_ll_end(const t_list *lst);

/// @brief Get the node of a list at position index
/// @param lst The list
/// @param index The index of the node
/// @return The node at index or NULL
t_list	*ft_ll_at(const t_list *lst, size_t index);

// ft_list/ft_list_ll_map.c

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @param del The function to delete the data if allocation fails
/// @return The new list
t_list	*ft_ll_map(const t_list *lst, t_data_tr f, t_data_apply del);

// ft_list/ft_list_ll_new.c

/// @brief Create a new node
/// @return The new node
t_list	*ft_ll_new(void);

// ft_list/ft_list_ll_pushpop.c

/// @brief Push a node at the beginning of the list
/// @param lst The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_list	*ft_ll_push(t_list **lst, const void *data);

/// @brief Push a node at the end of the list
/// @param lst The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_list	*ft_ll_push_back(t_list **lst, const void *data);

/// @brief Pop a node at the beginning of the list
/// @param lst The head of the list
/// @return The data of the node
void	*ft_ll_pop(t_list **lst);

/// @brief Pop a node at the end of the list
/// @param lst The head of the list
/// @return The data of the node
void	*ft_ll_pop_back(t_list **lst);

// ft_list/ft_list_ll_rev.c

/// @brief Reverse a list
/// @param head The head of the list
/// @return the new head of the list
t_list	*ft_ll_rev(t_list **head);

// ft_list/ft_list_ll_size.c

/// @brief Get the size of a list
/// @param lst The list
/// @return The size of the list
size_t	ft_ll_size(const t_list *lst);

/// @brief Get the size of a list
/// @param lst The list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_ll_size_match(const t_list *lst, t_data_is function);

// ft_list/ft_list_ll_sub.c

/// @brief Get a sublist of a list
/// @param src The list
/// @param to The node until which to get the sublist
/// @note The sublist is a copy of the original list but does not copy
/// the data in a new ptr. This is why it doesn't need a delete function.
/// @return The sublist
t_list	*ft_ll_subrange(const t_list *lst, const t_list *end);

#endif /* FT_LIST_H */
