/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:55:28 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/14 15:49:47 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
	char *str;
	size_t i;

	i = 0;
	if (s == 0)
		return 0;
	if(!(str = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return NULL;
	while(i < ft_strlen(s)) {
		str[i] = f(i,s[i]);
		i++;
	}
	str[i] = '\0';
	return str;
}
