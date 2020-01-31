/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_plane_inter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 13:48:09 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	sphere_n_pt(float t0, t_sphere *sphere, data_t *data)
{
	vect pt;
	vect n;

	pt = vectadd(data->ray.orig, vectmult(data->ray.dir, (double)t0));
	n = vectsub(pt, sphere->center);
	data->rgbt = sphere->rgb;
	temporary_value(data, t0, pt, n);
}

float	find_t0(float a, float b, float c)
{
	float t0;
	float t1;
	float discr;

	discr = (b * b) - (4 * a * c);
	if (discr == 0.0)
		t0 = -b / (2 * a);
	else
	{
		t0 = (-b + sqrt(discr)) / (2 * a);
		t1 = (-b - sqrt(discr)) / (2 * a);
		if (t0 < 0)
			return (t1);
		if (t1 < 0)
			return (t0);
		if (t0 > t1)
			t0 = t1;
	}
	return (t0);
}

void	inter_sphere(t_sphere *sphere, data_t *data)
{
	float	a;
	float	b;
	float	c;
	vect	vectos;

	vectos = vectsub(data->ray.orig, sphere->center);
	a = vectdot(data->ray.dir, data->ray.dir);
	b = 2 * vectdot(data->ray.dir, vectos);
	c = vectdot(vectos, vectos) - (sphere->radius * sphere->radius);
	if ((b * b) - (4 * a * c) >= 0.0000)
	{
		a = find_t0(a, b, c);
		sphere_n_pt(a, sphere, data);
	}
}

void	inter_plane(t_plane *plane, data_t *data)
{
	vect	pt;
	vect	p0l0;
	float	t;
	float	demom;

	plane->N = normalize(plane->N);
	if ((demom = vectdot(data->ray.dir, plane->N)) > 0)
		plane->N = vectmult(plane->N, -1);
	demom = vectdot(data->ray.dir, plane->N);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(plane->p0, data->ray.orig);
		t = vectdot(p0l0, plane->N) / demom;
		if (t >= 0.00001f)
		{
			pt = vectadd(data->ray.orig, vectmult(data->ray.dir, t));
			data->rgbt = plane->rgb;
			temporary_value(data, t, pt, plane->N);
		}
	}
}
