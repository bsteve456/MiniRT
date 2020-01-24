/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2020/01/24 14:50:38 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	display_list(t_list *scene, data_t *data)
{
	ambient_light(scene, data);
//	init_planes(scene, data);
	object_parse(scene, data);
}

void	window_loop(t_list *scene, data_t *data, t_cam *cam)
{
	float i;
	float j;
	i = 0;
	while(i < data->widw->x)
	{
		j = 0;
		while(j < data->widw->y)
		{
			data = complet_ray_pixel(i, j, cam, data);
			display_list(scene, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
}


void	camera_loop(t_list *scene)
{
	object	*cam_obj;
	data_t *data;
	t_list *copy;

	copy = scene;
	while(copy)
	{
		cam_obj = copy->content;
		data = init_data(scene); //error if data == NULL;
		if(cam_obj->type == 0)
			window_loop(scene, data, cam_obj->obj);
		copy = copy->next;
	}
}
