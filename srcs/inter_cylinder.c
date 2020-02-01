/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:30:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 17:41:31 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	top_bottom_cap(t_cylinder *cy, t_data *data)
{
	t_vect p1;

	p1 = vectadd(cy->p0, vectmult(cy->n, cy->height));
	cy->n = vectmult(cy->n, -1);
	inter_disk(cy, cy->p0, data);
	cy->n = vectmult(cy->n, -1);
	inter_disk(cy, p1, data);
}

float	find_delta(t_data *data, t_cylinder *cy, float *a)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	moo;
	float	abc[3];

	moo = vectsub(data->ray.orig, cy->p0);
	v1 = (vectsub(moo, vectmult(cy->n, vectdot(moo, cy->n))));
	v2 = (vectsub(data->ray.dir,
	vectmult(cy->n, vectdot(data->ray.dir, cy->n))));
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
	b = vectdot(mop, cy->n);
	mp = vectmult(cy->n, b);
	n = vectsub(mop, mp);
	return (n);
}

void	inter_cylinder(t_cylinder *cy, t_data *data)
{
	float	delta;
	float	a;
	float	b;
	t_vect	pt;
	t_vect	n;

	cy->n = normalize(cy->n);
	delta = find_delta(data, cy, &a);
	if (delta >= 0.0f)
	{
		pt = vectadd(data->ray.orig, vectmult(data->ray.dir, a));
		n = find_normal(pt, cy);
		b = vectdot(vectsub(pt, cy->p0), cy->n);
		if (b > 0 && b < cy->height)
		{
			data->rgbt = cy->rgb;
			temporary_value(data, a, pt, n);
		}
		else
			top_bottom_cap(cy, data);
	}
}
