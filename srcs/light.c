/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/09 17:06:51 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	light(vect Pt, t_sphere *sphere, data_t *data, t_light *light)
{
	vect N;
	vect L;
	float surface_color;

	N = vectSub(Pt, sphere->center);
	L = vectSub(Pt, light->orig);
//	N = normalize(N);
//	L = normalize(L);
	surface_color = ((0.1) / M_PI ) * (light->color * light->ratio) * vectDot(N, L);
	printf("%f\n", surface_color);
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
