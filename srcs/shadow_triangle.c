/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:00:00 by blacking          #+#    #+#             */
/*   Updated: 2020/01/30 09:07:29 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		shadow_triangle(t_sdaw d_ray, t_triangle *trgl)
{
	vect N;
	float t;
	vect Pt;

	N	= find_N(trgl);
	float demom = vectDot(d_ray.dir, N);
	if(fabs(demom) > 0.00001f)
	{
		vect p0l0 = vectSub(trgl->p0, d_ray.orig);
		t = vectDot(p0l0, N) / demom;
		if(t > 0.0f)
		{
			Pt = vectAdd(d_ray.orig, vectMult(d_ray.dir, (double)t));
			if(inter_triangle2(Pt, trgl, N) == 1)
				return (1);
		}
	}
	return (0);
}
