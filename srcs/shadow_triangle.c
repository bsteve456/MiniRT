/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:00:00 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 12:10:09 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float find_t_s(t_triangle *trgl, t_sdaw d_ray, vect *N)
{
	vect A;
	vect B;
	float D;
	float t;

	A = vectSub(trgl->p1, trgl->p0);
	B = vectSub(trgl->p2, trgl->p0);
	*N = normalize(crossP(A, B));
	D = vectDot(*N, trgl->p0);
	t = (vectDot(*N, d_ray.orig) + D) / vectDot(*N, d_ray.dir);
	return (t);
}

int		shadow_triangle(t_sdaw d_ray, t_triangle *trgl)
{
	vect N;
	float t;
	vect Pt;

	t = find_t_s(trgl, d_ray, &N);
	if(t > 0.0f)
	{
		Pt = vectAdd(d_ray.orig, vectMult(d_ray.dir, (double)t));
		if(inter_triangle2(Pt, trgl, N) == 1)
			return (1);
	}
	return (0);
}

