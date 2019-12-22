/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:13:32 by blacking          #+#    #+#             */
/*   Updated: 2019/10/17 16:48:48 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void const *content) {
	
	t_list *new;

	new = 0;
	if(!(new = ft_calloc(1, sizeof(t_list))))
		return NULL;
	new->content = (void *)content;
	new->next = NULL;
	return new;
}
