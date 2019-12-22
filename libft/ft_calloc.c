/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:55:26 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/09 16:55:28 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size) {

	unsigned char *data;
	if(!(data = (unsigned char *)malloc(size * count)))
		return NULL;
	ft_bzero((void *)data, size*count);
	return data;
}
