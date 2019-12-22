/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:48:06 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/19 15:40:30 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c) {
	int i;
	int mem;

	i = 0;
	mem = -1;
	if((unsigned char)c == '\0')
		return (char *)(s + ft_strlen(s));
	while(s[i]){
		if (((unsigned char *)s)[i] == (unsigned char)c)
			mem = i;
		i++;
	}
	if(mem != -1) {
		return (char *)(s + mem);
	}
	return 0;
}
