/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2019/12/29 15:01:09 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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
			printf("%f : %f\n  %f : %f : %f\n", i,
					j, data->ray.dir.x,data->ray.dir.y,data->ray.dir.z);
			j++;
		}
		i++;
	}
}


void	camera_loop(t_list *scene)
{
	object	*cam_obj;
	data_t *data;
	t_list *copy;

	data = init_data(scene); //error if data == NULL;
	copy = scene;
	while(copy)
	{
		cam_obj = copy->content;
		if(cam_obj->type == 0)
			window_loop(scene, data, cam_obj->obj);
		copy = copy->next;
	}
}
