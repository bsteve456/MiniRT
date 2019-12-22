/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:08:02 by blacking          #+#    #+#             */
/*   Updated: 2019/10/13 14:41:56 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len) {
	unsigned int i;
	size_t j;
	char *dst;

	i = 0;
	j = 0;
	if(!(dst = ft_calloc(len, sizeof(char))))
		return NULL;
	while(s[i] && j < len) {
		if(i >= start && j < len) {
			dst[j] = s[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return dst;
}
