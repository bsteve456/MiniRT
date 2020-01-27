/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:49:43 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/20 16:17:27 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list *list;
	t_list *temp;

	list = 0;
	temp = 0;
	if (l)
	{
		while (l)
		{
			if (!(temp = ft_lstnew(f(l->content))))
			{
				ft_lstclear(&list, d);
				return (NULL);
			}
			ft_lstadd_back(&list, temp);
			l = l->next;
		}
	}
	return (list);
}
