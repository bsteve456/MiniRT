/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:54:49 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 15:09:07 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	surface_color(data_t *data, t_color rgb)
{
	int		t_colora;
	t_color	rgbr;

	rgbr.r = (data->rgb.r > rgb.r) ? rgb.r : data->rgb.r;
	rgbr.g = (data->rgb.g > rgb.g) ? rgb.g : data->rgb.g;
	rgbr.b = (data->rgb.b > rgb.b) ? rgb.b : data->rgb.b;
	t_colora = rgbr.r * pow(256, 2) + rgbr.g * 256 + rgbr.b;
	if (t_colora < 0.0)
	{
		rgbr.r = 0;
		rgbr.g = 0;
		rgbr.b = 0;
	}
	put_color_to_window(data, rgbr);
}

void	reflected_color2(t_aligth *light, t_color *rgb)
{
	if (rgb->r < (light->rgb.r))
		rgb->r = light->rgb.r;
	if (rgb->g < (light->rgb.g))
		rgb->g = light->rgb.g;
	if (rgb->b < (light->rgb.b))
		rgb->b = light->rgb.b;
}

void	reflected_color(t_light *light, float dotp, t_color *rgb)
{
	if (rgb->r < (light->rgb.r * light->ratio * dotp))
		rgb->r = light->rgb.r * light->ratio * dotp;
	if (rgb->g < (light->rgb.g * light->ratio * dotp))
		rgb->g = light->rgb.g * light->ratio * dotp;
	if (rgb->b < (light->rgb.b * light->ratio * dotp))
		rgb->b = light->rgb.b * light->ratio * dotp;
}

void	light_loop(t_vect pt, t_vect n, data_t *data, t_list *scene)
{
	t_vect	l;
	t_object	*a_light;
	t_light	*light_a;
	t_list	*copy;
	t_color	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	copy = scene;
	n = normalize(n);
	while (scene)
	{
		a_light = scene->content;
		if (a_light->type == 4)
		{
			light_a = a_light->obj;
			l = normalize(vectsub(light_a->orig, pt));
			reflected_color(a_light->obj, vectdot(n, l), &rgb);
		}
		else if (a_light->type == 2)
			reflected_color2(a_light->obj, &rgb);
		scene = scene->next;
	}
	shadow_ray(copy, data, rgb);
}
