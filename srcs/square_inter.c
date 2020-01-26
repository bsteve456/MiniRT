/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:38:06 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 20:51:23 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

vect	square_corner_init(float x, float y, float z)
{
	vect p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

float orient(vect a, vect b, vect c, vect n)
{
	float res;
	vect v1;
	vect v2;

	v1 = vectSub(b, a);
	v2 = vectSub(c, a);
	res = vectDot(crossP(v1, v2), n);
	return (res);
}

int		dot_product(vect *corner, vect q, vect n)
{
	float o1;
	float o2;
	float o3;
	float o4;
	
	o1 = orient(q, corner[0], corner[1], n);
	o2 = orient(q, corner[1], corner[2], n);
	o3 = orient(q, corner[2], corner[3], n);
	o4 = orient(q, corner[3], corner[0], n);
	if((o1 >= 0 && o2 >= 0 && o3 >= 0 && o4 >= 0) ||
		(o1 < 0 && o2 < 0 && o3 < 0 && o4 < 0))
		return (1);
	return (0);
}

void	inter_square(vect Pt, t_square *square, data_t *data, float t)
{
	vect *square_corner = ft_calloc(4, sizeof(vect));

	square_corner[0] = square_corner_init(square->p0.x - square->height/2, 
		square->p0.y + square->height/2, square->p0.z);
	square_corner[1] = square_corner_init(square->p0.x + square->height/2, 
		square->p0.y + square->height/2, square->p0.z);
	square_corner[2] = square_corner_init(square->p0.x + square->height/2, 
		square->p0.y - square->height/2, square->p0.z);
	square_corner[3] = square_corner_init(square->p0.x - square->height/2, 
		square->p0.y - square->height/2, square->p0.z);
	data->rgb = square->rgb;
	if(dot_product(square_corner, Pt, square->N) == 1)
	{
		square->N.z = (square->N.z > 0) ? -square->N.z : square->N.z;
		data->rgbt = square->rgb;
		temporary_value(data, t, Pt, square->N);
	}
	free(square_corner);
}


void	inter_plane_square(t_square *square, data_t *data)
{
	vect p0l0;
	float t;
	float demom;
	vect Pt;

	square->N = normalize(square->N);
	demom = vectDot(data->ray.dir, square->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(square->p0, data->ray.orig);
		t = vectDot(p0l0, square->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			inter_square(Pt, square, data, t);
		}
	}
}
