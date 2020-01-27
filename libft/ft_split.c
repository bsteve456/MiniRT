/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:31:30 by blacking          #+#    #+#             */
/*   Updated: 2019/10/20 13:15:47 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_string(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count + 1);
}

static char		*ft_str(const char *s, int count)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_calloc(count + 1, sizeof(char))))
		return (NULL);
	while (i < count)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		index;
	int		j;
	char	**av;

	index = 0;
	j = 0;
	if (!(av = ft_calloc(ft_count_string(s, c) + 1, sizeof(char *))))
		return (NULL);
	while (s[index])
	{
		if (s[index] == c)
		{
			if (index != 0)
				av[j++] = ft_str(s, index);
			s = s + index + 1;
			index = -1;
		}
		else if (s[index + 1] == 0)
			av[j++] = ft_str(s, index + 1);
		index++;
	}
	av[j] = NULL;
	return (av);
}
