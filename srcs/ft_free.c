/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:21:08 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 21:06:09 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


void	free_data(data_t *data)
{
//	free(data->mlx_ptr);
//	free(data->mlx_win);
//	free(data->img);
//	free(data->img_data);
//	free(data->widw);
	free(data);
}

void	free_scene(t_list **scene)
{
	t_list *mem;
	object *content;
	if (*scene)
	{
		while(*scene)
		{
			mem = (*scene)->next;
			content = (*scene)->content;
			free(content);
			free(*scene);
			*scene = mem;
		}
	}
}

void	free_imga(t_lst **imga)
{
	t_lst *mem;
	if (*imga)
	{
		while((*imga)->next)
		{
			mem = (*imga)->next;
			free((*imga)->mlx_ptr);
			free((*imga)->mlx_win);
			free((*imga)->img);
			free((*imga)->img_data);
			free(*imga);
			*imga = mem;
		}
			free((*imga)->mlx_ptr);
			free((*imga)->mlx_win);
			free((*imga)->img);
			free(*imga);

	}
}
