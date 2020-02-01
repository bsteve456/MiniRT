/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:21:08 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 17:30:27 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_data(t_data *data)
{
	free(data);
}

void	free_imga(t_lst **imga)
{
	t_lst *mem;

	if (*imga)
	{
		while ((*imga))
		{
			mem = (*imga)->next;
			free(*imga);
			*imga = mem;
		}
	}
}
