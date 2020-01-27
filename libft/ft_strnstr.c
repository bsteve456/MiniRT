/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:56:42 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/20 15:36:05 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t j;

	j = 0;
	if (*l == '\0')
		return ((char *)b);
	while (*b && j < len)
	{
		if (ft_strncmp(b, l, ft_strlen(l)) == 0
			&& j + ft_strlen(l) <= len)
			return ((char *)b);
		b++;
		j++;
	}
	return (0);
}
