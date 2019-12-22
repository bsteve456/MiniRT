/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:39:07 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/19 18:59:03 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
	t_list *list;
	t_list *temp;

	list = 0;
	temp = 0;
	if(lst) {
		while(lst) {
			if(!(temp = ft_lstnew(f(lst->content))))
 			{
				ft_lstclear(&list, del);
				return NULL;
			}
			ft_lstadd_back(&list, temp);
			lst = lst->next;
		}
	}
	return list;
}
