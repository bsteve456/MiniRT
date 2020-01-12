/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/12 10:36:57 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		reflected_color(t_light *light, float dotP)
{
	int r;
	int g;
	int b;

	r = light->rgb.r * light->ratio * dotP;
	g = light->rgb.g * light->ratio * dotP;
	b = light->rgb.b * light->ratio * dotP;

	return (r * pow(256, 2) + g * 256 + b);
}

void	light(vect Pt, t_sphere *sphere, data_t *data, t_light *light)
{
	vect N;
	vect L;
	int surface_color;

	N = vectSub(Pt, sphere->center);
	L = vectSub(light->orig, Pt);
	N = normalize(N);
	L = normalize(L);
	surface_color = reflected_color(light, vectDot(N,L));
	if(surface_color < 0.0)
		surface_color *= 0.0;
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, surface_color);
}

void	light_loop(float t0, t_sphere *sphere, data_t *data, t_list *scene)
{
	vect Pt;
	object *t_light;
	Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t0));
	while(scene)
	{
		t_light = scene->content;
		if(t_light->type == 4)
			light(Pt, sphere, data, t_light->obj);
		scene = scene->next;
	}
}
