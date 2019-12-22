/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:33:10 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/19 15:21:41 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if(src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if(size != 0) {
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}
