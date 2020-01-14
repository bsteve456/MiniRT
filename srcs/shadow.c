/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:25:01 by blacking          #+#    #+#             */
/*   Updated: 2020/01/14 20:35:55 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	shadow_inter(vect Pt, t_light *light, t_list *scene)
{
	t_sdaw d_ray;
	object *obj;

	d_ray.orig = Pt;
	d_ray.dir = vectMult(vectSub(d_ray.orig, light->orig), -1);
	while(scene)
	{
		obj = scene->content;
		if(obj->type == 3)
			if(inter_shadow_sphere(d_ray, obj->obj) == 1)
				return (1);
		scene = scene->next;
	}
	return (0);
}


int	shadow_ray(t_list *scene, vect Pt, data_t *data, vect N)
{
	object *light;
	t_list *copy;
	int num = 0;
	Pt = vectMult(vectAdd(Pt, N), 1);
	copy = scene;
	while(copy)
	{
		light = copy->content;
		if(light->type == 4)
			num = shadow_inter(Pt, light->obj, scene);
		copy = copy->next;
	}
	return num;
}
