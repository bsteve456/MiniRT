/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:45:57 by blacking          #+#    #+#             */
/*   Updated: 2019/10/20 13:30:57 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (0);
		set++;
	}
	return (1);
}

static int		ft_isset_last(char const *s1, char const *set)
{
	while (*s1)
	{
		if (ft_isset(*s1, set) == 1)
			return (1);
		s1++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		index;
	char	*str;

	i = 0;
	index = 0;
	if (!(str = ft_calloc(ft_strlen(s1) + 1, sizeof(char const))))
		return (NULL);
	while (s1[index])
	{
		if (ft_isset(s1[index], set) == 0 && index == 0)
		{
			s1 += index + 1;
			index = -1;
		}
		else if (ft_isset_last(s1 + index, set) == 1
			|| ft_isset(s1[index], set) == 1)
		{
			str[i] = s1[index];
			i++;
		}
		index++;
	}
	str[i] = '\0';
	return (str);
}
