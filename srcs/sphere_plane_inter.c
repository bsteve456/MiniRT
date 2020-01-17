/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_plane_inter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2020/01/17 12:14:40 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


void	sphere_n_pt(float t0, t_sphere *sphere, data_t *data, t_list *scene)
{
	vect Pt;
	vect N;

	Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)t0));
	N = vectSub(Pt, sphere->center);
	data->rgb = sphere->rgb;
	if(shadow_ray(scene, Pt, data) == 0)
		light_loop(Pt, N, data, scene);
}

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
		sphere_n_pt(a, sphere, data, scene);
	}
}

void	inter_plane(t_plane *plane, data_t *data, t_list *scene)
{
	vect Pt;
	vect p0l0;
	float t;
	float demom;

	demom = vectDot(data->ray.dir, plane->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(plane->p0, data->ray.orig);
		t = vectDot(p0l0, plane->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			data->rgb = plane->rgb;
			if(shadow_ray(scene, Pt, data) == 0)
				light_loop(Pt, plane->N, data, scene);
		}
	}
}
