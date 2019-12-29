/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2019/12/29 13:52:20 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	camera_loop(t_list *scene)
{
	object	*cam_obj;
	data_t *data;
	t_list *copy;

	data = init_data(scene); //error if data == NULL;
	copy = scene;
	 if ((data.mlx_win =
	mlx_new_window(data.mlx_ptr, widw.x, widw.y, "minirt")) == NULL)
        return (EXIT_FAILURE);
	while(copy)
	{
		cam_obj = copy->content;
		if(cam_obj->type == 0)
			window_loop(scene, data, cam_obj->obj);
		copy = copy->next;
	}
}
