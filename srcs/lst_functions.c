/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:14:08 by blacking          #+#    #+#             */
/*   Updated: 2020/01/25 14:41:39 by blacking         ###   ########.fr       */
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
	new->next = NULL;
	return new;
}

void	lstadd_back(t_lst **alst, t_lst *new, int n)
{
	t_lst *lst;

	new->n = n;
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
