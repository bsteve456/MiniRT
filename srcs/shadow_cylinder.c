/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:52:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 17:42:14 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		inter_disk1(t_cylinder *cy, t_vect p, t_sdaw d_ray)
{
	t_vect	pt;
	t_vect	p0l0;
	float	t;
	float	demom;
	float	d1;

	demom = vectdot(d_ray.dir, cy->n);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(p, d_ray.orig);
		t = vectdot(p0l0, cy->n) / demom;
		if (t >= 0.00001f)
		{
			pt = vectadd(d_ray.orig, vectmult(d_ray.dir, t));
			d1 = vectdot(vectsub(pt, p), vectsub(pt, p));
			if (sqrt(d1) <= cy->radius)
				return (1);
		}
	}
	return (0);
}

int		top_bottom_cap1(t_cylinder *cy, t_sdaw d_ray)
{
	t_vect p1;

	p1 = vectadd(cy->p0, vectmult(cy->n, cy->height));
	cy->n = vectmult(cy->n, -1);
	if (inter_disk1(cy, cy->p0, d_ray) == 1)
	{
		cy->n = vectmult(cy->n, -1);
		return (1);
	}
	cy->n = vectmult(cy->n, -1);
	if (inter_disk1(cy, p1, d_ray) == 1)
		return (1);
	return (0);
}

float	find_delta_s(t_sdaw d_ray, t_cylinder *cy, float *a)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	moo;
	float	abc[3];

	moo = vectsub(d_ray.orig, cy->p0);
	v1 = (vectsub(moo, vectmult(cy->n, vectdot(moo, cy->n))));
	v2 = (vectsub(d_ray.dir,
	vectmult(cy->n, vectdot(d_ray.dir, cy->n))));
	abc[0] = vectdot(v2, v2);
	abc[1] = 2 * vectdot(v1, v2);
	abc[2] = vectdot(v1, v1) - (cy->radius * cy->radius);
	*a = find_t0(abc[0], abc[1], abc[2]);
	return ((abc[1] * abc[1]) - (4 * abc[0] * abc[2]));
}

int		shadow_cylinder(t_sdaw d_ray, t_cylinder *cy)
{
	float	delta;
	t_vect	pt;
	float	a;
	float	b;
	t_vect	n;

	cy->n = normalize(cy->n);
	delta = find_delta_s(d_ray, cy, &a);
	if (delta > 0.0f && a > 0)
	{
		pt = vectadd(d_ray.orig, vectmult(d_ray.dir, a));
		n = find_normal(pt, cy);
		b = vectdot(vectsub(pt, cy->p0), cy->n);
		if (b > 0 && b < cy->height)
			return (1);
		else if (top_bottom_cap1(cy, d_ray) == 1)
			return (1);
	}
	return (0);
}
