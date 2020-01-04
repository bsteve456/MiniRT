/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:25:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/30 10:57:52 by blacking         ###   ########.fr       */
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
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, light->rgb * light->ratio);
			break;
		}
		scene = scene->next;
	}
}

void	object_parse(t_list *scene, data_t *data, t_cam *cam)
{
	object *obj;

	while(scene)
	{
		obj = scene->content;
		if(obj->type == 3)
			inter_sphere(obj->obj, data->ray, data, cam);
		scene = scene->next;
	}
}