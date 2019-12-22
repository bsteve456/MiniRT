/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:37:46 by stbaleba          #+#    #+#             */
/*   Updated: 2019/10/18 13:47:47 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *)) {
	if (lst) {
		while(lst) {
			//printf("%s\n", (unsigned char *)lst->content);
			f(lst->content);
			lst = lst->next;
		}
	}
}
