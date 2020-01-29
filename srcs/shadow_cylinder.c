/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:52:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/29 12:10:22 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		inter_disk1(t_cylinder *cy, vect p, t_sdaw d_ray)
{
	vect Pt;
	vect p0l0;
	float t;
	float demom;

	demom = vectDot(d_ray.dir, cy->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(p, d_ray.orig);
		t = vectDot(p0l0, cy->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(d_ray.orig, vectMult(d_ray.dir, t));
			vect v = vectSub(Pt, p);
			float d1 = vectDot(v, v);
			if(sqrt(d1) <= cy->radius)
				return (1);
		}
	}
	return (0);
}


int		top_bottom_cap1(t_cylinder *cy, t_sdaw d_ray)
{
		vect p1;

		p1 = vectAdd(cy->p0, vectMult(cy->N, cy->height));
		cy->N = vectMult(cy->N, -1);
		if(inter_disk1(cy, cy->p0, d_ray) == 1){
			cy->N = vectMult(cy->N, -1);
			return  (1);
		}
		cy->N = vectMult(cy->N, -1);
		if(inter_disk1(cy, p1, d_ray) == 1)
			return (1);
		return (0);
}

float find_delta_s(t_sdaw d_ray, t_cylinder *cy, float *a)
{
	vect V1;
	vect V2;
	vect MoO;
	float abc[3];

	MoO = vectSub(d_ray.orig, cy->p0);
	V1 = (vectSub(MoO, vectMult(cy->N,  vectDot(MoO, cy->N))));
	V2 = (vectSub(d_ray.dir,
	vectMult(cy->N, vectDot(d_ray.dir, cy->N))));
	abc[0] = vectDot(V2, V2);
	abc[1] = 2  * vectDot(V1, V2);
	abc[2] = vectDot(V1, V1) - (cy->radius * cy->radius);
	*a = find_t0(abc[0], abc[1], abc[2]);
	return ((abc[1] * abc[1]) - (4 * abc[0] * abc[2]));
}

int		shadow_cylinder(t_sdaw d_ray, t_cylinder *cy)
{
	float delta;
	vect Pt;
	float a;
	float b;
	vect N;

	cy->N = normalize(cy->N);
	delta = find_delta_s(d_ray, cy, &a);
	if(delta > 0.0f && a > 0)
	{
		Pt = vectAdd(d_ray.orig, vectMult(d_ray.dir, a));
		N = find_normal(Pt, cy);

		b = vectDot(vectSub(Pt, cy->p0), cy->N);
		if(b > 0 && b < cy->height)
				return (1);
		else if(top_bottom_cap1(cy, d_ray) == 1)
			return (1);
	}
	return (0);
}
