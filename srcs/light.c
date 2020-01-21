/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/21 14:36:11 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	surface_color(data_t *data, color rgb)
{
	int color;
	int r;
	int g;
	int b;

	r = (data->rgb.r > rgb.r) ? rgb.r : data->rgb.r;
	g = (data->rgb.g > rgb.g) ? rgb.g : data->rgb.g;
	b = (data->rgb.b > rgb.b) ? rgb.b : data->rgb.b;
	color = r * pow(256, 2) + g * 256 + b;
	if(color < 0.0)
		color *= 0.0;
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, color);
}

void		reflected_color(t_light *light, float dotP, color *rgb)
{
	if (rgb->r < (light->rgb.r * light->ratio * dotP))
			rgb->r = light->rgb.r * light->ratio * dotP;
	if (rgb->g < (light->rgb.g * light->ratio * dotP))
			rgb->g = light->rgb.g * light->ratio * dotP;
	if (rgb->b < (light->rgb.b * light->ratio * dotP))
			rgb->b = light->rgb.b * light->ratio * dotP;
}

void	light_loop(vect Pt, vect N, data_t *data, t_list *scene)
{
	vect L;
	object *a_light;
	t_light *light_a;
	color rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	N = normalize(N);
	while(scene)
	{
		a_light = scene->content;
		if(a_light->type == 4)
		{
			light_a = a_light->obj;
			L = normalize(vectSub(light_a->orig, Pt));
			if(Pt.x == 0.0f && Pt.y == 0.0f)
			{
//				printf("N : %f,%f, %f\n", N.x,N.y,N.z);
//				printf("%f\n%f, %f, %f\n",vectDot(N, L), Pt.x, Pt.y, Pt.z);
			}
			reflected_color(a_light->obj,vectDot(N, L), &rgb);
		}
		scene = scene->next;
	}
	surface_color(data, rgb);
}
