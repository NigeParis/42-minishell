/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:51:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:52:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_TESTS_H
# define DL_TESTS_H

int	t_dladd_front(void);
int	t_dladd_back(void);

int	t_dlapply(void);
int	t_dlapply_range(void);
int	t_dlapply_range_node(void);

int	t_dlclear(void);
int	t_dlclear_range(void);

int	t_dlcreate(void);

int	t_dlcopy_node(void);
int	t_dlcopy_list(void);

int	t_dl_delete_self(void);
int	t_dldelete_range(void);
int	t_dldelete(void);

int	t_dlfind(void);

int	t_dlget_datas(void);
int	t_dlget_nodes(void);

int	t_dl_at(void);
int	t_dl_begin(void);
int	t_dl_end(void);

int	t_dl_map(void);

int	t_dl_new(void);

int	t_dl_pop(void);
int	t_dl_pop_back(void);
int	t_dl_push(void);
int	t_dl_push_back(void);

int	t_dl_rev(void);

int	t_dl_size(void);
int	t_dl_size_of_data(void);

int	t_dl_subrange(void);

#endif /* DL_TESTS_H */
