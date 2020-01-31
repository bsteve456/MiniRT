/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:49:09 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:23:48 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	find_n(t_triangle *trgl)
{
	t_vect a;
	t_vect b;
	t_vect n;

	a = vectsub(trgl->p1, trgl->p0);
	b = vectsub(trgl->p2, trgl->p0);
	n = crossp(a, b);
	return (n);
}

float	inter_triangle2(t_vect pt, t_triangle *trgl, t_vect n)
{
	t_vect edge[3];
	t_vect c[3];

	edge[0] = vectsub(trgl->p1, trgl->p0);
	edge[1] = vectsub(trgl->p2, trgl->p1);
	edge[2] = vectsub(trgl->p0, trgl->p2);
	c[0] = vectsub(pt, trgl->p0);
	c[1] = vectsub(pt, trgl->p1);
	c[2] = vectsub(pt, trgl->p2);
	if (vectdot(n, crossp(edge[0], c[0])) >= -0.001f &&
		vectdot(n, crossp(edge[1], c[1])) >= -0.001f &&
		vectdot(n, crossp(edge[2], c[2])) >= -0.001f)
		return (1);
	return (0);
}

int		inter_triangle(t_triangle *trgl, data_t *data)
{
	t_vect	n;
	float	t;
	t_vect	pt;
	float	demom;
	t_vect	p0l0;

	n = find_n(trgl);
	demom = vectdot(data->ray.dir, n);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(trgl->p0, data->ray.orig);
		t = vectdot(p0l0, n) / demom;
		if (t >= 0.00001f)
		{
			pt = vectadd(data->ray.orig, vectmult(data->ray.dir, (double)t));
			if (inter_triangle2(pt, trgl, n) == 1)
			{
				n = (demom >= 0) ? vectmult(n, -1) : n;
				data->rgbt = trgl->rgb;
				temporary_value(data, t, pt, n);
				return (1);
			}
		}
	}
	return (0);
}
