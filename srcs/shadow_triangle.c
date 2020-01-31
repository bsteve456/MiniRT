/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:00:00 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 13:50:38 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		shadow_triangle(t_sdaw d_ray, t_triangle *trgl)
{
	vect	n;
	float	t;
	vect	pt;
	float	demom;
	vect	p0l0;

	n = find_n(trgl);
	demom = vectdot(d_ray.dir, n);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(trgl->p0, d_ray.orig);
		t = vectdot(p0l0, n) / demom;
		if (t > 0.0f)
		{
			pt = vectadd(d_ray.orig, vectmult(d_ray.dir, (double)t));
			if (inter_triangle2(pt, trgl, n) == 1)
				return (1);
		}
	}
	return (0);
}
