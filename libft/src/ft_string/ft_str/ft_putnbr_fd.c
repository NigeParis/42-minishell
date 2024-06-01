/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:08:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:43:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "ft_char.h"
#include "ft_string.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		return (ft_putchar_fd('0', fd));
	if (nbr < 0)
	{
		if (nbr == INT_MIN)
			return ((void)write(fd, "-2147483648", 11));
		write(fd, "-", 1);
		return (ft_putnbr_fd(-nbr, fd));
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd("0123456789"[nbr % 10], fd);
}
