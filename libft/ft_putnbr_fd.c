/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:26:04 by blacking          #+#    #+#             */
/*   Updated: 2019/10/15 14:53:28 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd) {
	unsigned int nb;
	char c;
	if(fd != -1) {
			if (n < 0) {
				c = '-';
				write(fd, &c, 1 );
				nb = -n;
			}
			else
				nb = n;
			c = nb % 10 + '0';
			if(nb >= 10)
				ft_putnbr_fd(nb / 10, fd);
			write(fd, &c, 1);
	}
}
