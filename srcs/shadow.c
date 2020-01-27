/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:25:01 by blacking          #+#    #+#             */
/*   Updated: 2020/01/27 16:25:29 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		shadow_inter2(t_sdaw d_ray, object *obj, int n, int nbis)
{
	if(obj->type == 3)
	{
		if(n != nbis && inter_shadow_sphere(d_ray, obj->obj) == 1)
			return (1);
	}
	else if(obj->type == 5)
	{
		if(n != nbis && inter_shadow_plane(d_ray, obj->obj) == 1)
			return (1);
	}
	else if(obj->type == 6)
	{
		if(n != nbis && shadow_square(d_ray, obj->obj) == 1)
			return (1);
	}
	else if(obj->type == 7)
	{
		if(n != nbis && shadow_cylinder(d_ray, obj->obj) == 1)
			return (1);
	}
	else if(obj->type == 8)
	{
		if(n != nbis && shadow_triangle(d_ray, obj->obj) == 1)
			return (1);
	}
	return (0);
}

int		shadow_inter(vect Pt, t_light *light, t_list *scene, int n)
{
	t_sdaw d_ray;
	object *obj;
	int nbis = 0;

	d_ray.orig = Pt;
	d_ray.dir = vectMult(vectSub(d_ray.orig, light->orig), -1);
	d_ray.light_orig = light->orig;
	while(scene)
	{
		obj = scene->content;
		if (shadow_inter2(d_ray, obj, n, nbis) == 1)
			return (1);
		nbis++;
		scene = scene->next;
	}
	return (0);
}

int		shadow_ray(t_list *scene, data_t *data, int n)
{
	object *light;
	t_list *copy;
	int num;
	color rgb;

	copy = scene;
	num = 0;
	while(copy)
	{
		light = copy->content;
		if(light->type == 4)
			num += shadow_inter(data->Pt, light->obj, scene, n);
		copy = copy->next;
	}
	if(num > 0)
	{
		rgb.r = data->rgb.r * pow(0.5, num);
		rgb.g = data->rgb.g * pow(0.5, num);
		rgb.b = data->rgb.b * pow(0.5, num);
		surface_color(data, rgb);
	}
	return (num);
}
