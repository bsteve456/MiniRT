/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:42:47 by blacking          #+#    #+#             */
/*   Updated: 2019/12/29 13:49:25 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.c"

t_widw	object_widw(t_list *copy)
{
	object *widw;
	while(copy)
	{
		widw = copy->content;
		if(widw->type = 1)
			return (widw->copy);
		copy = copy->next;
	}
	return (NULL);
}

data_t init_data(t_list *copy)
{
	data_t *res;
	t_widw widw;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	widw = object_widw(copy);
	if(widw == NULL)
		return (NULL);
	data->width = widw.x;
	data->heigth = widw.y;
	if ((data.mlx_win =
				mlx_new_window(data.mlx_ptr, widw.x, widw.y, "minirt")) == NULL)
		return (EXIT_FAILURE);
	return (res);
}
