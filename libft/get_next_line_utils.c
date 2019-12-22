/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:20:01 by blacking          #+#    #+#             */
/*   Updated: 2019/12/22 16:00:49 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr_gnl(char *prev_cumul, unsigned int start, size_t len)
{
	char *line_or_cumul;
	unsigned int i = 0;
	unsigned int j = 0;
	if(!(line_or_cumul = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while(prev_cumul[i])
	{
		if(start == 0 && prev_cumul[i] == '\n')
			return(line_or_cumul);
		if(i >= start)
		{
			line_or_cumul[j] = prev_cumul[i];
			j++;
		}
		i++;
	}
	if(start != 0)
		free(prev_cumul);
	return (line_or_cumul);
}
