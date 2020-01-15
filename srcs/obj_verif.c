/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2020/01/15 14:38:27 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float find_t0(float a, float b, float c)
{
	float t0;
	float t1;
	float discr;

	discr = (b * b) - (4 * a * c);
	if(discr == 0.0)
		t0 = -b / (2 * a);
	else
	{
		t0 = (-b + sqrt(discr)) / (2 * a);
		t1 = (-b - sqrt(discr)) / (2 * a);
		if(t0 > t1)
			t0 = t1;
	}
	return (t0);
}

void	inter_sphere(t_sphere *sphere, data_t *data, t_list *scene)
{
	float a;
	float b;
	float c;
	vect vectOS;

	vectOS = vectSub(data->ray.orig, sphere->center);
	a = vectDot(data->ray.dir, data->ray.dir);
	b = 2 * vectDot(data->ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	if((b * b) - (4 * a * c) >= 0.0000)
	{
		a = find_t0(a, b, c);
		vect Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)a));
		vect N = vectSub(Pt, sphere->center);
		Pt = vectMult(vectAdd(Pt, N), 0.9);
		data->rgb = sphere->rgb;
		if(shadow_ray(scene, Pt, data) == 0)
			light_loop(Pt, N, data, scene);
	}
}

void	inter_plane(t_plane *plane, data_t *data, t_list *scene)
{
	int color;

	color = plane->rgb.r * pow(256, 2) + plane->rgb.g * 256 + plane->rgb.b;
	plane->N = plane->N;
	float demom = vectDot(data->ray.dir, plane->N);
	if(fabs(demom) > 0.00001f) {
		vect p0l0 = vectSub(plane->p0, data->ray.orig);
		float t = vectDot(p0l0, plane->N) / demom;

		if(t >= 0.00001f)
		{
			vect Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			data->rgb = plane->rgb;

			if(shadow_ray(scene, Pt, data) == 0)
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, color);
		}
	}
}
