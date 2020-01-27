/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:02:38 by blacking          #+#    #+#             */
/*   Updated: 2019/10/20 13:20:17 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	j;

	if (!(dst = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1,
		sizeof(char const))))
		return (NULL);
	j = 0;
	while (*s1 || *s2)
	{
		if (*s1)
		{
			dst[j] = *s1;
			s1++;
		}
		else if (*s2)
		{
			dst[j] = *s2;
			s2++;
		}
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
