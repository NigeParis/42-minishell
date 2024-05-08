/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:22:33 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 12:48:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_insert(t_string *str, char *insert, size_t index)
{
	size_t	insert_len;
	size_t	new_len;
	char	*new_str;

	insert_len = ft_strlen(insert);
	new_len = str->length + insert_len;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert, insert_len);
	ft_memcpy(new_str + index + insert_len, str->str + index,
		str->length - index);
	ft_free((void **) &str->str);
	str->str = new_str;
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_n(t_string *str, char *insert, size_t index, size_t n)
{
	size_t	new_len;
	char	*new_str;

	new_len = str->length + n;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert, n);
	ft_memcpy(new_str + index + n, str->str + index, str->length - index);
	ft_free((void **)&str->str);
	str->str = new_str;
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_c(t_string *str, char insert, size_t index)
{
	size_t	new_len;
	char	*new_str;

	new_len = str->length + 1;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memcpy(new_str, str->str, index);
	new_str[index] = insert;
	ft_memcpy(new_str + index + 1, str->str + index, str->length - index);
	ft_free((void **)&str->str);
	str->str = new_str;
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_s(t_string *str, t_string *insert, size_t index)
{
	size_t	new_len;
	char	*new_str;

	new_len = str->length + insert->length;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert->str, insert->length);
	ft_memcpy(new_str + index + insert->length, str->str + index,
		str->length - index);
	ft_free((void **)&str->str);
	str->str = new_str;
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}

int	ft_string_insert_s_n(t_string *str, t_string *insert, size_t index,
	size_t n)
{
	size_t	new_len;
	char	*new_str;

	new_len = str->length + n;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memcpy(new_str, str->str, index);
	ft_memcpy(new_str + index, insert->str, n);
	ft_memcpy(new_str + index + n, str->str + index, str->length - index);
	ft_free((void **)&str->str);
	str->str = new_str;
	str->length = new_len;
	str->capacity = new_len + 1;
	return (1);
}
