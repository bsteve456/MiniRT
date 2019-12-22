/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:56:42 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/19 16:01:16 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t j;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && j < len)
	{
		if(ft_strncmp(haystack, needle, ft_strlen(needle)) == 0 
			&& j + ft_strlen(needle) <= len)
				return ((char *)haystack);
		haystack++;
		j++;
	}
	return (0);
}
