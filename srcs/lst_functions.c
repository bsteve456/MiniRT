/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:14:08 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 17:57:05 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_lst *lstnew(data_t *content)
{

	t_lst *new;

	new = 0;
	if(!(new = ft_calloc(1, sizeof(t_lst))))
		return NULL;
	new->mlx_ptr = content->mlx_ptr;
	new->mlx_win = content->mlx_win;
	new->img = content->img;
	new->img_data = content->img_data;
	new->x = content->widw->x;
	new->y = content->widw->y;
	new->next = NULL;
	return new;
}

void	lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst *lst;

	lst = *alst;
	if (!lst)
		*alst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
