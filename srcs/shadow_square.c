/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:38:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 12:09:25 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		dot_product_s(vect *corner, vect q, vect n)
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

int		inter_square_s(vect Pt, t_square *square)
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
	if(dot_product_s(square_corner, Pt, square->N) == 1)
	{
		free(square_corner);
		return (1);
	}
	free(square_corner);
	return (0);
}


int		shadow_square(t_sdaw d_ray, t_square *square)
{
	vect p0l0;
	float t;
	float demom;
	vect Pt;

	square->N = normalize(square->N);
	demom = vectDot(d_ray.dir, square->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(square->p0, d_ray.orig);
		t = vectDot(p0l0, square->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(d_ray.orig, vectMult(d_ray.dir, t));
			if(inter_square_s(Pt, square) == 1)
				return (1);
		}
	}
	return (0);
}

