/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:25:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/16 12:05:50 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ambient_light(t_list *scene, data_t *data)
{
	object *alight;
	t_aligth *light;
	int color;

	while(scene)
	{
		alight = scene->content;
		if(alight->type == 2)
		{
			light = alight->obj;
			color = light->rgb.r * pow(256, 2) +
			light->rgb.g * 256 + light->rgb.b;
			mlx_pixel_put(data->mlx_ptr, data->mlx_win,
			data->x, data->y, color * light->ratio);
			break;
		}
		scene = scene->next;
	}
}

void	init_planes(t_list *scene, data_t *data)
{
	object *a_plane;
	t_plane *plane;
	t_list *copy;

	copy = scene;
	while(scene)
	{
		a_plane = scene->content;
		if(a_plane->type == 5)
		{
			plane = a_plane->obj;
			inter_plane(plane, data, copy);
		}
		scene = scene->next;
	}
}

void	object_parse(t_list *scene, data_t *data)
{
	object *obj;
	t_list *copy;

	copy = scene;
	while(scene)
	{
		obj = scene->content;
		if(obj->type == 3)
			inter_sphere(obj->obj, data, copy);
		else if(obj->type == 6)
			inter_plane_square(obj->obj, data);
		scene = scene->next;
	}
}
