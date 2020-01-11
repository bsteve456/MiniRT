/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/11 15:06:43 by blacking         ###   ########.fr       */
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
	L = vectSub(light->orig, Pt);
//	L = vectMult(data->ray.dir, 1);
	N = normalize(N);
	L = normalize(L);
	float a = vectDot(N, L);
//	printf("N: %f, %f, %f\n", N.x, N.y, N.z);
//	printf("L :%f, %f, %f\n", L.x, L.y, L.z);
//	surface_color = (light->color * light->ratio) * vectDot(N, L);
	surface_color = mlx_get_color_value(data->mlx_ptr ,pow(255, 1) * a); 
//	printf("N: %f, %f, %f\n", N.x, N.y, N.z);
//	printf("L :%f, %f, %f\n", L.x, L.y, L.z);
//	printf("NL : %f\n", floor(vectDot(N, L)*10)/10);
	if(surface_color < 0.0)
		surface_color *= 0.0;	
	printf("NL : %f\n", vectDot(N, L));
	printf("color : %f\n", surface_color);
//	if(surface_color > 255 * 2)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, (surface_color));
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
