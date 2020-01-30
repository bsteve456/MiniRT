/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:38:06 by blacking          #+#    #+#             */
/*   Updated: 2020/01/30 12:51:39 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

vect	square_corner_init(float a, float b, float c)
{
		vect res;

		res.x = a;
		res.y = b;
		res.z = c;
		return (res);
}

int		inter_plane_square(t_square *square, data_t *data)
{
	t_triangle trgl2;
	t_triangle trgl1;

	vect Oy = square_corner_init(0, 1, 0);
	vect OP1 = crossP(square->N, Oy);
	float d = sqrt(2 * square->height * square->height) / 2;
	OP1 = vectMult(OP1, d);
	vect p1 = vectAdd(square->p0 , OP1);
	vect OP2 = crossP(square->N, OP1);
	vect p2 = vectAdd(square->p0, OP2);
	vect OP3 = crossP(square->N, OP2);
	vect p3 = vectAdd(square->p0, OP3);
	vect OP4 = crossP(square->N, OP3);
	vect p4 = vectAdd(square->p0, OP4);
	trgl1.p0 = p1;
	trgl1.p1 = p2;
	trgl1.p2 = p4;
	trgl2.p0 = p3;
	trgl2.p1 = p2;
	trgl2.p2 = p4;
	if(inter_triangle(&trgl1, data) == 1 || inter_triangle(&trgl2, data) == 1)
	{
		data->rgbt = square->rgb;
		return (1);
	}
	return (0);
}
