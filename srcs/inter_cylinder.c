/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:30:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 14:44:18 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"../includes/minirt.h"

void	top_bottom_cap(t_cylinder *cy, vect Pt, data_t *data, t_list *scene)
{
		vect p1;

		p1 = vectAdd(cy->p0, vectMult(cy->N, cy->height));
		inter_disk(cy, cy->p0, data, scene);
		inter_disk(cy, p1, data, scene);
}

float find_delta(data_t *data, t_cylinder *cy, float *a)
{
	vect V1;
	vect V2;
	vect MoO;
	float abc[3];

	MoO = vectSub(data->ray.orig, cy->p0);
	V1 = (vectSub(MoO, vectMult(cy->N,  vectDot(MoO, cy->N))));
	V2 = (vectSub(data->ray.dir, 
	vectMult(cy->N, vectDot(data->ray.dir, cy->N))));
	abc[0] = vectDot(V2, V2);
	abc[1] = 2  * vectDot(V1, V2);
	abc[2] = vectDot(V1, V1) - (cy->radius * cy->radius);
	*a = find_t0(abc[0], abc[1], abc[2]);
	return ((abc[1] * abc[1]) - (4 * abc[0] * abc[2]));
}

vect find_normal(vect Pt, t_cylinder *cy)
{
	vect MoP;
	vect Mp;
	float b;
	vect N;

	MoP = vectSub(Pt, cy->p0);
	b = vectDot(MoP, cy->N);
	Mp = vectMult(cy->N, b);
	N = vectSub(MoP, Mp);
	return (N);
}

void	inter_cylinder(t_cylinder *cy, data_t *data, t_list *scene)
{
	float delta;
	float a;
	float b;
	vect Pt;
	vect N;

	cy->N = normalize(cy->N);
	delta = find_delta(data, cy, &a);
	if(delta >= 0.0f)
	{
		data->rgb = cy->rgb;
		Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)a));
		N = find_normal(Pt, cy);
		b = vectDot(vectSub(Pt, cy->p0), cy->N);
		if(b > 0 && b < cy->height)
		{
			data->rgbt = cy->rgb;
			temporary_value(data, a, Pt, N);
		}
		else 
			top_bottom_cap(cy, Pt, data, scene);
	}
}
