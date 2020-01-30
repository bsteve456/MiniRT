/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:31:10 by blacking          #+#    #+#             */
/*   Updated: 2020/01/30 17:02:13 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*substr_gnl(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*dst;

	i = 0;
	j = 0;
	if (!(dst = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (s[i] && j < len)
	{
		if (start == 0 && s[i] == '\n')
		{
			dst[j] = '\0';
			return (dst);
		}
		else if (i >= start && j < len)
			dst[j++] = s[i];
		i++;
	}
	if (start != 0)
		free(s);
	dst[j] = '\0';
	return (dst);
}
