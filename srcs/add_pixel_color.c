/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:25:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 20:59:14 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ambient_light(t_list *scene, data_t *data)
{
	object *alight;
	t_aligth *light;

	while(scene)
	{
		alight = scene->content;
		if(alight->type == 2)
		{
			light = alight->obj;
			put_color_to_window(data, light->rgb);
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
			inter_plane(obj->obj, data);
		if(obj->type == 3)
			inter_sphere(obj->obj, data);
		else if(obj->type == 6)
			inter_plane_square(obj->obj, data);
		else if(obj->type == 7)
			inter_cylinder(obj->obj, data);
		else if(obj->type == 8)
			inter_triangle(obj->obj, data);
		check_order_object(data);
		scene = scene->next;
	}
	if(data->t != -1 && shadow_ray(copy, data) == 0)
		light_loop(data->Pt, data->N, data, copy);
}
