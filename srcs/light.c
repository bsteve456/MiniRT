/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/24 20:48:26 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	surface_color(data_t *data, color rgb)
{
	int colora;
	color rgbr;

	rgbr.r = (data->rgb.r > rgb.r) ? rgb.r : data->rgb.r;
	rgbr.g = (data->rgb.g > rgb.g) ? rgb.g : data->rgb.g;
	rgbr.b = (data->rgb.b > rgb.b) ? rgb.b : data->rgb.b;
	colora = rgbr.r * pow(256, 2) + rgbr.g * 256 + rgbr.b;
	if(colora < 0.0)
	{
		rgbr.r = 0;
		rgbr.g = 0;
		rgbr.b = 0;
	}
	put_color_to_window(data, rgbr);
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
			reflected_color(a_light->obj,vectDot(N, L), &rgb);
		}
		scene = scene->next;
	}
	surface_color(data, rgb);
}
