/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:25:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 14:43:23 by blacking         ###   ########.fr       */
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

void	object_parse(t_list *scene, data_t *data)
{
	object *obj;
	t_list *copy;

	copy = scene;
	data->t = -1;
	data->temp = -1;
	while(scene)
	{
		obj = scene->content;
		if(obj->type == 5)
			inter_plane(obj->obj, data, copy);
		if(obj->type == 3)
			inter_sphere(obj->obj, data, copy);
		else if(obj->type == 6)
			inter_plane_square(obj->obj, data, copy);
		else if(obj->type == 7)
			inter_cylinder(obj->obj, data, copy);
		else if(obj->type == 8)
			inter_triangle(obj->obj, data, copy);
		check_order_object(data);
		scene = scene->next;
	}
	if(data->t != -1 && shadow_ray(copy, data) == 0)
		light_loop(data->Pt, data->N, data, copy);
}
