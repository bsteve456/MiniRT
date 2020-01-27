/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:45:42 by blacking          #+#    #+#             */
/*   Updated: 2019/10/20 13:43:10 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *mem;

	if (*lst)
	{
		while (*lst)
		{
			mem = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = mem;
		}
	}
}
