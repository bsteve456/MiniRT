/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:49:09 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 14:45:15 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float find_t(t_triangle *trgl, data_t *data, vect *N)
{
	vect A;
	vect B;
	float D;
	float t;

	A = vectSub(trgl->p1, trgl->p0);
	B = vectSub(trgl->p2, trgl->p0);
	*N = normalize(crossP(A, B));
	D = vectDot(*N, trgl->p0);
	t = (vectDot(*N, data->ray.orig) + D) / vectDot(*N, data->ray.dir);
	return (t);
}

float	inter_triangle2(vect Pt, t_triangle *trgl, vect N)
{
	vect edge[3];
	vect C[3];

	edge[0] = vectSub(trgl->p1, trgl->p0);
	edge[1] = vectSub(trgl->p2, trgl->p1);
	edge[2] = vectSub(trgl->p0, trgl->p2);
	C[0] = vectSub(Pt, trgl->p0);
	C[1] = vectSub(Pt, trgl->p1);
	C[2] = vectSub(Pt, trgl->p2);
	if(vectDot(N, crossP(edge[0], C[0])) > 0 &&
		vectDot(N, crossP(edge[1], C[1])) > 0 &&
		vectDot(N, crossP(edge[2], C[2])) > 0)
		return (1);
	return (0);
}

void	inter_triangle(t_triangle *trgl, data_t *data, t_list *scene)
{
	vect N;
	float t;
	vect Pt;

	t = find_t(trgl, data, &N);
	if(t > 0.0f)
	{
		Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)t));
		if(inter_triangle2(Pt, trgl, N) == 1)
		{
			data->rgbt = trgl->rgb;
			temporary_value(data, t, Pt, N);
		}
	}
}

