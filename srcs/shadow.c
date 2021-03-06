/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:25:01 by blacking          #+#    #+#             */
/*   Updated: 2020/02/01 09:36:12 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		shadow_inter2(t_sdaw d_ray, t_object *obj, t_data *data, int nbis)
{
	if (obj->type == 3 && data->na != nbis &&
	inter_shadow_sphere(d_ray, obj->obj) == 1)
		return (1);
	else if (obj->type == 5 && data->na != nbis &&
	inter_shadow_plane(d_ray, obj->obj) == 1)
		return (1);
	else if (obj->type == 6 && data->na != nbis &&
	shadow_square(d_ray, obj->obj) == 1)
		return (1);
	else if (obj->type == 7 && data->na != nbis &&
	shadow_cylinder(d_ray, obj->obj) == 1)
		return (1);
	else if (obj->type == 8 && data->na != nbis &&
	shadow_triangle(d_ray, obj->obj) == 1)
		return (1);
	return (0);
}

int		shadow_inter(t_data *data, t_light *light, t_list *scene)
{
	t_sdaw		d_ray;
	t_object	*obj;
	int			nbis;

	nbis = 0;
	d_ray.orig = data->pt;
	d_ray.dir = normalize(vectsub(light->orig, d_ray.orig));
	d_ray.light_orig = light->orig;
	while (scene)
	{
		obj = scene->content;
		if (shadow_inter2(d_ray, obj, data, nbis) == 1)
			return (1);
		nbis++;
		scene = scene->next;
	}
	return (0);
}

int		shadow_ray(t_list *scene, t_data *data, t_color rgb)
{
	t_object	*light;
	t_list		*copy;
	int			num;
	int			a;

	copy = scene;
	num = 0;
	a = 0;
	while (copy)
	{
		light = copy->content;
		if (light->type == 4)
			num += shadow_inter(data, light->obj, scene);
		else if (light->type == 2)
			a++;
		copy = copy->next;
	}
	if (a != 1 || num != 0)
	{
		rgb.r = rgb.r * pow(0.5, num);
		rgb.g = rgb.g * pow(0.5, num);
		rgb.b = rgb.b * pow(0.5, num);
	}
	surface_color(data, rgb);
	return (num);
}
