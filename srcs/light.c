/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/10 16:40:51 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	light(vect Pt, t_sphere *sphere, data_t *data, t_light *light)
{
	vect N;
	vect L;
	float surface_color;

//	sphere->center = normalize(sphere->center);
//	light->orig = normalize(light->orig);
	N = vectSub(Pt, sphere->center);
	L = vectSub(Pt, light->orig);
//	L = vectMult(data->ray.dir, 1);
	N = normalize(N);
	L = normalize(L);
//	printf("N: %f, %f, %f\n", N.x, N.y, N.z);
//	printf("L :%f, %f, %f\n", L.x, L.y, L.z);
	surface_color = light->color * light->ratio * (vectDot(N, L));
	if(vectDot(N, L) >= -0.05)
	{
		printf("N: %f, %f, %f\n", N.x, N.y, N.z);
		printf("L :%f, %f, %f\n", L.x, L.y, L.z);
		printf("NL : %f\n", vectDot(N, L) / M_PI);
		printf("color : %f\n", surface_color);
	}
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, surface_color);
}

void	light_loop(float t0, t_sphere *sphere, data_t *data, t_list *scene)
{
	vect Pt;
	object *t_light;
	Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t0));
//	Pt = normalize(Pt);
//	printf("Pt :%f, %f, %f\n", Pt.x, Pt.y, Pt.z);
	while(scene)
	{
		t_light = scene->content;
		if(t_light->type == 4)
			light(Pt, sphere, data, t_light->obj);
		scene = scene->next;
	}
}
