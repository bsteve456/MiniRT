/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:54:18 by blacking          #+#    #+#             */
/*   Updated: 2019/10/10 21:19:57 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
	size_t i;

	i = 0;
	while(i < n) {
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return s;
}
