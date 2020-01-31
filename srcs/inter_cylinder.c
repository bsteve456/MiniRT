/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:30:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:22:18 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	top_bottom_cap(t_cylinder *cy, data_t *data)
{
	t_vect p1;

	p1 = vectadd(cy->p0, vectmult(cy->N, cy->height));
	cy->N = vectmult(cy->N, -1);
	inter_disk(cy, cy->p0, data);
	cy->N = vectmult(cy->N, -1);
	inter_disk(cy, p1, data);
}

float	find_delta(data_t *data, t_cylinder *cy, float *a)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	moo;
	float	abc[3];

	moo = vectsub(data->ray.orig, cy->p0);
	v1 = (vectsub(moo, vectmult(cy->N, vectdot(moo, cy->N))));
	v2 = (vectsub(data->ray.dir,
	vectmult(cy->N, vectdot(data->ray.dir, cy->N))));
	abc[0] = vectdot(v2, v2);
	abc[1] = 2 * vectdot(v1, v2);
	abc[2] = vectdot(v1, v1) - (cy->radius * cy->radius);
	*a = find_t0(abc[0], abc[1], abc[2]);
	return ((abc[1] * abc[1]) - (4 * abc[0] * abc[2]));
}

t_vect	find_normal(t_vect pt, t_cylinder *cy)
{
	t_vect	mop;
	t_vect	mp;
	float	b;
	t_vect	n;

	mop = vectsub(pt, cy->p0);
	b = vectdot(mop, cy->N);
	mp = vectmult(cy->N, b);
	n = vectsub(mop, mp);
	return (n);
}

void	inter_cylinder(t_cylinder *cy, data_t *data)
{
	float	delta;
	float	a;
	float	b;
	t_vect	pt;
	t_vect	n;

	cy->N = normalize(cy->N);
	delta = find_delta(data, cy, &a);
	if (delta >= 0.0f)
	{
		pt = vectadd(data->ray.orig, vectmult(data->ray.dir, a));
		n = find_normal(pt, cy);
		b = vectdot(vectsub(pt, cy->p0), cy->N);
		if (b > 0 && b < cy->height)
		{
			data->rgbt = cy->rgb;
			temporary_value(data, a, pt, n);
		}
		else
			top_bottom_cap(cy, data);
	}
}
